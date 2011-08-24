
#include "pch.h"
#include "WarModeOne.h"
#include "Application.h"
#include "UIWarone.h"
#include "EnemyQueue.h"
#include "UIWarTwoBalance.h"



//----------------------------------------------------------------------------
WarModeOne::WarModeOne(GameState* pGameState)
:WarMode(pGameState),m_pWarManager(NULL),m_pSceneMrg(NULL),m_GameLeft(10.0f),
m_CurrentTime(0.0f),m_needCreate(false),m_pUI(NULL),m_Minx(-90.0f),m_Maxx(90.0f),
m_Miny(-60.0f),m_Maxy(60.0f),m_Minz(1.5f),m_Maxz(5.0f),m_KillCount(0),m_LostCount(0),
m_EnemyLeftTime(3.0f),m_pUIBalance(NULL)
{

   initUI();
	
}


//----------------------------------------------------------------------------
WarModeOne::~WarModeOne()
{

	destroyUI();

}


//----------------------------------------------------------------------------
void WarModeOne::start()
{

	m_pWarManager=WarManager::getSingletonPtr();

	m_pWarManager->startWar();
	m_pWarManager->addListener(this);

	m_pSceneMrg=Application::getSingleton().getMainSceneManager();

	//���������
	Application::getSingleton().getMainCamera()->getParentSceneNode()->resetOrientation();

    initEnemyFormat();
	m_CurrentTime=0.0f;
	m_needCreate=true;

	m_KillCount=0;
	m_LostCount=0;

}


//----------------------------------------------------------------------------
void WarModeOne::end()
{
	m_pWarManager->removeListener(this);

}

//----------------------------------------------------------------------------
void WarModeOne::update(float time)
{

	
	m_CurrentTime+=time;
	if(m_CurrentTime>m_GameLeft)
	{
		///��������
		if(WarManager::getSingleton().isGameEnd()==false)
		{
			WarManager::getSingleton().endWar();
			m_pUIBalance->setVisible(true);
		}
		

		return ;
	}


	if(m_pUI!=NULL)
	{
		m_pUI->setTime(m_GameLeft-m_CurrentTime);
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

	m_pUIBalance=new UIWarTowModeBalance(this);
	m_pUIBalance->init();
	m_pUIBalance->setVisible(false);
	Application::getSingleton().registerUI(m_pUIBalance);

}

//----------------------------------------------------------------------------
void  WarModeOne::destroyUI()
{
	Application::getSingleton().destroyUI(m_pUI);
	m_pUI=NULL;

	Application::getSingleton().destroyUI(m_pUIBalance);
	m_pUIBalance=NULL;


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

			///��������÷�Χ��С��
			if(sec=="Enemylimits")
			{
				if(type=="Minx")
				{
					m_Minx=Ogre::StringConverter::parseReal(arch);
				}else if(type=="Maxx")
				{
					m_Maxx=Ogre::StringConverter::parseReal(arch);
				}else if(type=="Miny")
				{
					m_Miny=Ogre::StringConverter::parseReal(arch);
				}else if(type=="Maxy")
				{
					m_Maxy=Ogre::StringConverter::parseReal(arch);
				}else if(type=="Minz")
				{
					m_Minz=Ogre::StringConverter::parseReal(arch);
				}else if(type=="Maxz")
				{
					m_Maxz=Ogre::StringConverter::parseReal(arch);
				}else if(type=="LeftTime")
				{
					m_EnemyLeftTime=Ogre::StringConverter::parseReal(arch);
				}



			}else
			{

			
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

	EnemyQueue* pQueue= WarManager::getSingleton().createEnemyQueue(m_Minx,m_Maxx,m_Miny,m_Maxy,m_Minz,m_Maxz,m_EnemyFormatCollect[createindex].m_EnemyCollect,
		m_EnemyFormatCollect[createindex].m_FriendCollect);
	pQueue->setLeftTime(m_EnemyLeftTime);

	++m_CreateIndex;
	m_needCreate=false;
	return ;

}

//----------------------------------------------------------------------------
void WarModeOne::onKillEnemyQueue(EnemyQueue* pEnemyQueue)
{
	m_needCreate=true;
	++m_KillCount;

}

//----------------------------------------------------------------------------
void WarModeOne::onLostEnemyQueue(EnemyQueue* pEnemyQueue)
{
   ++m_LostCount;
	m_needCreate=true;
}

//----------------------------------------------------------------------------
void WarModeOne::beginTouch(int x,int y)
{

	WarManager::getSingleton().fire();
}