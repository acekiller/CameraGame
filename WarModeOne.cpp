
#include "pch.h"
#include "WarModeOne.h"
#include "Application.h"
#include "UIWarone.h"



//----------------------------------------------------------------------------
WarModeOne::WarModeOne(GameState* pGameState)
:WarMode(pGameState),m_pWarItemManager(NULL),m_pSceneMrg(NULL),m_GameLeft(60.0f),
m_CurrentTime(0.0f),m_needCreate(false),m_pUI(NULL)
{


}


//----------------------------------------------------------------------------
WarModeOne::~WarModeOne()
{


}


//----------------------------------------------------------------------------
void WarModeOne::start()
{

	m_pWarItemManager=WarManager::getSingletonPtr();

	m_pWarItemManager->startWar();
	m_pWarItemManager->addListener(this);

	m_pSceneMrg=Application::getSingleton().getMainSceneManager();

    initEnemyFormat();

	initUI();

	m_CurrentTime=0.0f;
	m_needCreate=true;

}


//----------------------------------------------------------------------------
void WarModeOne::end()
{

	destroyUI();

	m_pWarItemManager->removeListener(this);


}

//----------------------------------------------------------------------------
void WarModeOne::update(float time)
{

	
	m_CurrentTime+=time;
	if(m_CurrentTime>m_GameLeft)
	{
		///��������
		WarManager::getSingleton().endWar();
		return ;
	}


	if(m_needCreate)
	{
		_createEnemyQueue();
	}



	return ;

}

//----------------------------------------------------------------------------
void WarModeOne::updateAccelerometer()
{

	Ogre::SceneNode* pCameraNode=Application::getSingleton().getMainCameraNode();

	Ogre::Vector3 gyrco=InputListen::getSingleton().getGyroscopeData();
	float yawtem=gyrco.y;
	float pitch=gyrco.z;

	pitch+=Ogre::Math::PI*0.5f;

	if(pCameraNode!=NULL )
	{
		pCameraNode->resetOrientation();
		pCameraNode->pitch(Ogre::Radian(-pitch));
		pCameraNode->yaw(Ogre::Radian(yawtem),Ogre::Node::TS_WORLD);

	}

	return ;
}



//----------------------------------------------------------------------------
void  WarModeOne::initUI()
{

	m_pUI=new UIWarone();
    m_pUI->init();
	Application::getSingleton().registerUI(m_pUI);

}

//----------------------------------------------------------------------------
void  WarModeOne::destroyUI()
{
	Application::getSingleton().destroyUI(m_pUI);
	m_pUI=NULL;


}


//----------------------------------------------------------------------------
void  WarModeOne::initEnemyFormat()
{


	m_EnemyFormatCollect.clear();

	Ogre::DataStreamPtr pDataStream=Ogre::ResourceGroupManager::getSingleton().openResource("EnemyFormatMode1.cfg","General");
	
	
	if(pDataStream.isNull())
	{
		OGRE_EXCEPT(0,"can't find warmode1 enemyFormat file","WarModeOne::initEmemyFormat()");
	}


	Ogre::ConfigFile cf;

#if OGRE_PLATFORM == OGRE_PLATFORM_IPHONE

	OgreBites::FileSystemLayerImpl* pFileSystem=Application::getSingleton().getFileSystem();
	cf.load(pFileSystem->getConfigFilePath(g_EnemyFormat));

#else 
	cf.load(pDataStream);

#endif


	///ѭ��ȡ�����еĶ��к�λ����Ϣ
	Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
	Ogre::String sec, type, arch;

	//��ȡ��������
	while (seci.hasMoreElements())
	{
		sec = seci.peekNextKey();

		Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator i;
		if(settings->empty())
			continue;

		EnemyFormat enemyFormat;
		m_EnemyFormatCollect.push_back(enemyFormat);

		for (i = settings->begin(); i != settings->end(); i++)
		{
			type = i->first;
			arch = i->second;
			Ogre::Vector3 Pos=Ogre::StringConverter::parseVector3(arch);
			if(type=="Enemy")
			{	
				m_EnemyFormatCollect.back().m_EnemyCollect.push_back(Pos);
			}else if(type=="Friend")
			{
				m_EnemyFormatCollect.back().m_FriendCollect.push_back(Pos);
			}

		}


	}





	return ;

}


/**����һ������*/
//----------------------------------------------------------------------------
void  WarModeOne::_createEnemyQueue()
{

	///�������ʹ�����֮�Ͼ��Ǵ����Ķ�������
	unsigned int createindex=m_CreateIndex;

	///���С�ڶ������Ͱ����г�
	if(createindex>=m_EnemyFormatCollect.size())
	{
		::srand( time(0) );    //�趨���������
		createindex=::rand()%m_EnemyFormatCollect.size();
	}

	WarManager::getSingleton().createEnemyQueue(90,60,m_EnemyFormatCollect[createindex].m_EnemyCollect,
		m_EnemyFormatCollect[createindex].m_FriendCollect);

	++m_CreateIndex;
	m_needCreate=false;
	return ;

}

//----------------------------------------------------------------------------
void WarModeOne::onKillEnemyQueue(EnemyQueue* pEnemyQueue)
{
	m_needCreate=true;

}

//----------------------------------------------------------------------------
void WarModeOne::onLostEnemyQueue(EnemyQueue* pEnemyQueue)
{

	m_needCreate=true;
}

//----------------------------------------------------------------------------
void WarModeOne::beginTouch(int x,int y)
{

	WarManager::getSingleton().fire();
}