#include "pch.h"
#include "WarModeThree.h"
#include "UIWarModeThree.h"
#include "Application.h"
#include "WarManager.h"
#include "WarItem.h"
#include "WarItemManager.h"
#include "enemy.h"
#include "WarItem.h"

//----------------------------------------------------------------
WarModeThree::WarModeThree(GameState* pGameState)
:WarMode(pGameState),m_pUIWar(NULL),m_CurrentPower(0.0f),m_MaxPower(15.0f),
m_StopFireTime(0.0f),m_LastFireTime(0.0f),m_pWarItemManager(NULL),m_pTargetEnemy(NULL)
{

}


//----------------------------------------------------------------
WarModeThree::~WarModeThree()
{

}


//----------------------------------------------------------------
void WarModeThree::start()
{

	initUI();


	m_pWarItemManager=new WarItemManager();
	///����һ��ģ��
	WarManager::getSingleton().startWar();
	m_pTargetEnemy=WarManager::getSingleton().createEnemy(Ogre::Vector3(0,0,0));
	


	///��ʼ�������б�
	m_AnimationCollect.push_back("shiai");
	m_AnimationCollect.push_back("diantou");
	m_AnimationCollect.push_back("tiaomei");
	m_AnimationCollect.push_back("gusaibang");
	m_AnimationCollect.push_back("zhayan");
	m_AnimationCollect.push_back("ku");
	m_AnimationCollect.push_back("xiexiao");


	m_LastFireTime=0.0f;
	m_pTargetEnemy->playAnimation(m_AnimationCollect[0],true,0.5f);

}


//----------------------------------------------------------------
void WarModeThree::end()
{

	destroyUI();
	WarManager::getSingleton().endWar();
	SafeDelete(m_pWarItemManager);

	

}

//----------------------------------------------------------------
void WarModeThree::update(float time)
{

	m_pWarItemManager->update(time);


	///����������
	updatePower(time);

	m_LastFireTime+=time;
}



//-----------------------------------------------------------------
void WarModeThree::beginTouch(int x,int y)
{
	

	/**
	*ֻ�е������Ŀ���ʱ�Żᷢ�����
	*/
	if(m_pTargetEnemy==NULL)
		return ;

	///�������һ�ν���ʱ��С��һ��ͺ���
	if(m_LastFireTime<0.5f)
		return ;
	m_LastFireTime=0.0f;


	Ogre::Camera* pCamera=Application::getSingleton().getMainCamera();
    float viewx=x,viewy=y;
	float w = Application::getSingleton().getRenderWindows()->getViewport(0)->getActualWidth();
	float  h= Application::getSingleton().getRenderWindows()->getViewport(0)->getActualHeight();
	Ogre::Ray ray=pCamera->getCameraToViewportRay(viewx/w,viewy/h);


	const Ogre::AxisAlignedBox& box=m_pTargetEnemy->getSceneNode()->_getWorldAABB();
	float d1=0,d2=0;
	if(Ogre::Math::intersects(ray,box,&d1,&d2)==false)
	{
		return ;
	}

	WarItemType itemType=m_pUIWar->getCurrentItemType();
	if(itemType==WIT_NONE)
		return ;
	WarItem* pItem= m_pWarItemManager->createWarItem(itemType);
	pItem->begin();
	pItem->setTarget(m_pTargetEnemy);
	pItem->setListen(this);

	

	return ;
}


//----------------------------------------------------------------
void WarModeThree::initUI()
{
	m_pUIWar=new UIWarModeThree(this);
	m_pUIWar->init();
	Application::getSingleton().registerUI(m_pUIWar);

}


//----------------------------------------------------------------
void WarModeThree::destroyUI()
{
	Application::getSingleton().destroyUI(m_pUIWar);
	m_pUIWar=NULL;

	
}

//--------------------------------------------------------------------
void WarModeThree::updatePower(float time)
{
	m_StopFireTime+=time;
	if(m_StopFireTime>3.0)
	{
		m_CurrentPower-=time*3;////ÿ�������
		
	}else
	{

	}


    m_CurrentPower=std::max(m_CurrentPower,0.0f);//����С��0

	///���������۵ĳ���
	m_pUIWar->setPowerPercent(m_CurrentPower/m_MaxPower);
    
	///ֻ�����������˲Ż���ʾ���հ�ť
	

}


//--------------------------------------------------------------------
void  WarModeThree::onHitTarget(WarItem* pItem,Enemy* pEnemy)
{

	m_StopFireTime=0;
	float power= pItem->getPower();
	m_CurrentPower+=power;



	size_t size=m_AnimationCollect.size();

	unsigned int AniIndex=::rand()%size;
	pEnemy->playAnimation(m_AnimationCollect[AniIndex],false,0.0f);

	return ;

}