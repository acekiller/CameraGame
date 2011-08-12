#include "pch.h"
#include "WarItem.h"
#include "Application.h"
#include "enemy.h"


//-----------------------------------------------------------------------
EggItem::EggItem(const Ogre::String&MeshName,const Ogre::String&textureName,float Power)
:WarItem(WIT_EGG,Power),m_StartPos(0.0f,-1.0f,4.0f),m_pParentNode(NULL),m_pEntity(NULL),m_liftTime(0.0f),
m_TextreuName(textureName)
{

	//assert(pEnemy);
	//setTarget(pEnemy);

	initEntity(MeshName);

}

//-----------------------------------------------------------------------
EggItem::~EggItem()
{
    
destroyEntiy();

}


//-----------------------------------------------------------------------
void  EggItem::begin()
{

	///�����һ��лת����

	//m_pParentNode.rotate()

	m_pRotateDir.x=Ogre::Math::RangeRandom(0.0f,1.0f);
	m_pRotateDir.y=Ogre::Math::RangeRandom(0.0f,1.0f);
	m_pRotateDir.z=Ogre::Math::RangeRandom(0.0f,1.0f);
	m_pRotateDir.normalise();

	m_liftTime=0.0f;

}


//-----------------------------------------------------------------------
bool   EggItem::update(float time)
{

	m_liftTime+=time;
	if(m_liftTime>5.0f)
	{
		end();
		return false;
	}

	///���������ײ����Ŀ���������ͼ
	if(hitTarget())
	{
        end(); ///����ʹ�����
		return false ;
	}

	float RotateSpeed=Ogre::Math::PI;///180.0f*200.0f;
	m_pParentNode->rotate(m_pRotateDir,time*Ogre::Radian(RotateSpeed));

	float speed=1.0f;
	Ogre::Vector3 pos=m_pParentNode->getPosition();
	Ogre::Vector3 targetPos=m_pTarget->getSceneNode()->getPosition();

	Ogre::Vector3 dir=targetPos-pos;
	dir.normalise();
	m_pParentNode->translate(dir*speed*time,Ogre::Node::TS_WORLD);
	return true;

}

//-----------------------------------------------------------------------
void EggItem::end()
{
	if(m_TextreuName.empty()==false)
	{
     m_pTarget->setHitEffectTextureName(m_TextreuName);
	}
	

	///�㲥����Ŀ��
	fireHitTarget();


}

//-----------------------------------------------------------------------
void EggItem::initEntity(const Ogre::String& meshName)
{

	///����ģ�͡�����λ�á�
	Ogre::SceneManager* pSceneMrg=Application::getSingleton().getMainSceneManager();
	m_pParentNode=pSceneMrg->getRootSceneNode()->createChildSceneNode();
	m_pEntity=pSceneMrg->createEntity(meshName);
	m_pParentNode->attachObject(m_pEntity);
	m_pParentNode->setPosition(m_StartPos);
   // m_pParentNode->setScale(Ogre::Vector3(1,0.1,1));
	


}

//-----------------------------------------------------------------------
void EggItem::destroyEntiy()
{
	m_pParentNode->detachAllObjects();
	m_pParentNode->getParentSceneNode()->removeAndDestroyChild(m_pParentNode->getName());

	Ogre::SceneManager* pSceneMrg=Application::getSingleton().getMainSceneManager();
	pSceneMrg->destroyEntity(m_pEntity);
	m_pEntity=NULL;

}


//-----------------------------------------------------------------------
bool EggItem::hitTarget()
{
	 //const Ogre::AxisAlignedBox& bulletBox=m_pParentNode->_getWorldAABB();
    const Ogre::Vector3 pos=m_pParentNode->getPosition();
    const Ogre::AxisAlignedBox& box=m_pTarget->getSceneNode()->_getWorldAABB();
	return 	box.contains(pos);
}