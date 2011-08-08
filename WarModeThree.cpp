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
m_StopFireTime(0),m_pWarItemManager(NULL),m_pTargetEnemy(NULL)
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
}



//-----------------------------------------------------------------
void WarModeThree::beginTouch(int x,int y)
{
	

	/**
	*ֻ�е������Ŀ���ʱ�Żᷢ�����
	*/
	if(m_pTargetEnemy==NULL)
		return ;


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


    std::max(m_CurrentPower,0.0f);//����С��0

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
	return ;

}