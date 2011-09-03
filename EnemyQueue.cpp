#include "pch.h"
#include  "EnemyQueue.h"
#include "Application.h"
#include "Config.h"
#include "Bullet.h"
#include "enemy.h"
#include "WarManager.h"


//-----------------------------------------------------------------
EnemyQueue::EnemyQueue(const Ogre::Vector3& pos,const  PositionList&EnemyList,const PositionList& FriendList )
:m_pSceneMrg(NULL),m_pRootNode(NULL),m_State(EQ_NORMAl),m_currentLeftTime(0.0f),m_leftTime(3.0f)
{

	m_pSceneMrg=Application::getSingleton().getMainSceneManager();
	m_pRootNode=m_pSceneMrg->getRootSceneNode()->createChildSceneNode();
    m_pRootNode->setPosition(pos);
	//m_pRootNode->showBoundingBox(true);

	size_t size=EnemyList.size();
	for(size_t i=0;i<size;++i)
	{
		const Ogre::String& faceMesh=g_userInformation.getFaceMode();
		const Ogre::String& headMesh=g_userInformation.getHeadMode();
		Enemy* pEnemy=new Enemy(faceMesh,headMesh,EnemyList[i],m_pRootNode);
		pEnemy->registerEvent(EE_Hit,&EnemyQueue::notifyEnemyHit,this);
		m_ElemyCollect.push_back(pEnemy);

	}

	size= FriendList.size();
	for(size_t i=0;i<size;++i)
	{

		Enemy* pEnemy=new Enemy("puffer.mesh","",FriendList[i],m_pRootNode);
		pEnemy->registerEvent(EE_Hit,&EnemyQueue::notifyEnemyHit,this);
		m_FriendCollect.push_back(pEnemy);

	}


    ///���������
    

    
	Ogre::Camera* pCamera=Application::getSingleton().getMainCamera();
	Ogre::Vector3 camPos= pCamera->getParentNode()->getPosition();
	m_pRootNode->lookAt(camPos,Ogre::Node::TS_WORLD,Ogre::Vector3::UNIT_Z);
    

	



}



//-----------------------------------------------------------------
EnemyQueue::~EnemyQueue()
{

	destroy();
	

}



//-----------------------------------------------------------------
EnemyQueue::EQST EnemyQueue::update(float time)
{
	
	EnemyCollect::iterator it=m_ElemyCollect.begin();
	EnemyCollect::iterator endit=m_ElemyCollect.end();
	for(;it!=endit;++it)
	{
		(*it)->update(time);
	}

	it=m_FriendCollect.begin();
	endit=m_FriendCollect.end();
	for(;it!=endit;++it)
	{
		(*it)->update(time);
	}

    if(m_State==EQ_NORMAl)
    {
        updateNormal(time);
    
    }else   if(m_State==EQ_RUNAWAY)     //�������ڵ��ˣ���ʼ����
	{
		 updateLevelState(time);
	}else if(m_State==EQ_SWALLOWBALL)
	{
		updateSwallowBall(time);
	}

	return m_State;


}
//---------------------------------------------------------------------------
void  EnemyQueue::updateCollision(Bullet* pBullet)
{


	Ogre::Ray ray;
	float lenght=0.0f;
	if(pBullet->getFrameRay(ray,lenght)==false)
	{
        return ;
	}

	EnemyCollect::iterator it=m_ElemyCollect.begin();
	EnemyCollect::iterator endit=m_ElemyCollect.end();
	for(;it!=endit;++it)
	{
		bool hitMouth=false;
		if((*it)->intersectRay(ray,lenght,hitMouth,pBullet))
		{
			if((*it)->getState()==Enemy::ES_NORMAL)
			{
				(*it)->onHit(ray.getPoint(lenght),pBullet,hitMouth);

				if(hitMouth)
				{
					(*it)->onHitMouth(pBullet);
				}

				///�㲥����һ��Ŀ��
				WarManager::getSingleton().notifyKillEnemy(*it,hitMouth,pBullet);

			}
			pBullet->hitTarget();
			return ;
		}
	}



	it=m_FriendCollect.begin();
	endit=m_FriendCollect.end();
	for(;it!=endit;++it)
	{
		bool hitMouth=false;
		if((*it)->getState()==Enemy::ES_NORMAL&&(*it)->intersectRay(ray,lenght,hitMouth,pBullet))
		{
			(*it)->onHit(ray.getPoint(lenght),pBullet,hitMouth);
			 pBullet->hitTarget();
              
			 ///ͨ�д���һ������
			 WarManager::getSingleton().notifyHitFriend(*it);
			 return ;
		}
	}





	return ;

}


//-----------------------------------------------------------------
Ogre::AxisAlignedBox  EnemyQueue::getWordBox()
{

	Ogre::AxisAlignedBox box;


	EnemyCollect::iterator it=m_ElemyCollect.begin();
	EnemyCollect::iterator endit=m_ElemyCollect.end();
	for(;it!=endit;++it)
	{
		const Ogre::AxisAlignedBox temBox=(*it)->getSceneNode()->_getWorldAABB();
        box.merge(temBox);
	}

	it=m_FriendCollect.begin();
	endit=m_FriendCollect.end();
	for(;it!=endit;++it)
	{
		const Ogre::AxisAlignedBox temBox=(*it)->getSceneNode()->_getWorldAABB();
		box.merge(temBox);
	}




	return box;



}



//--------------------------------------------------------------------------
//bool EnemyQueue::intersectRay(const Ogre::Ray& ray,float length)
//{

	///�ȶ��������������һ����飬�������Ӧ�ٶ�����ÿһ�������������
	/*const Ogre::AxisAlignedBox& box=m_pRootNode->_getWorldAABB();
	float nearPoint(0.0f),farPoint(0.0f);
	bool intersect=	Ogre::Math::intersects(ray,box,&nearPoint,&farPoint);
	if(intersect==false)
	{
		return false;
	}*/


//	EnemyCollect::iterator it=m_ElemyCollect.begin();
//	EnemyCollect::iterator endit=m_ElemyCollect.end();
//	for(;it!=endit;++it)
//	{
//		if((*it)->intersectRay(ray,length))
//		{
//			(*it)->onHit()
//			return true;
//		}
//	}
//
//
//	it=m_FriendCollect.begin();
//	endit=m_FriendCollect.end();
//	for(;it!=endit;++it)
//	{
//		if((*it)->intersectRay(ray,length))
//		{
//			return true;
//		}
//	}
//
//
//	return false;
//
//
//}

//--------------------------------------------------------------------------
void EnemyQueue::destroy()
{

	EnemyCollect::iterator it=m_ElemyCollect.begin();
	EnemyCollect::iterator endit=m_ElemyCollect.end();
	for(;it!=endit;++it)
	{
		delete (*it);
	}
     m_ElemyCollect.clear();


	it=m_FriendCollect.begin();
	endit=m_FriendCollect.end();
	for(;it!=endit;++it)
	{
		delete (*it);
	}
	m_FriendCollect.clear();


	m_pRootNode->removeAndDestroyAllChildren();
	m_pSceneMrg->getRootSceneNode()->removeAndDestroyChild(m_pRootNode->getName());

}

//--------------------------------------------------------------------------
void EnemyQueue::notifyEnemyHit(Enemy* pEnemy)
{
	
	if(hasFriendKilled()) //�����������,�Ϳ�ʼ����
	{
		m_State=EQ_RUNAWAY;
		///ȷ������ķ���
		m_currentLeftTime=0.0f;
		startRunaway();
		WarManager::getSingleton().notifyEnemyQueuLost(this);
		return ;

	}else if(isHitAllEnemy())///������е�Ŀ��㶼��������
	{
	    startLove();
		m_State=EQ_SWALLOWBALL;
		m_currentLeftTime=0.0f;
		WarManager::getSingleton().notifyKillEnemyQueu(this);
		return ;       

	}

	return ;

}


//--------------------------------------------------------------------------
bool  EnemyQueue::hasFriendKilled() const 
{
	///����������ڵ��ˡ�����
	EnemyCollect::const_iterator it=m_FriendCollect.begin();
	EnemyCollect::const_iterator endit=m_FriendCollect.end();
	for(;it!=endit;++it)
	{
		if((*it)->getState()>Enemy::ES_NORMAL)
		{
			return true;
		}
	}

	return false;

}


/**�Ƿ��к���״�ĵ�Ŀ��*/
bool  EnemyQueue::hasSwallowBallEnemy()const
{
	EnemyCollect::const_iterator it=m_ElemyCollect.begin();
	EnemyCollect::const_iterator endit=m_ElemyCollect.end();
	for(;it!=endit;++it)
	{
		if((*it)->getState()==Enemy::ES_SWALLOWBALL)
		{
			return true;
		}
	}

	return false;


}


//--------------------------------------------------------------------------
bool   EnemyQueue::isHitAllEnemy() const 
{
	EnemyCollect::const_iterator it=m_ElemyCollect.begin();
	EnemyCollect::const_iterator endit=m_ElemyCollect.end();
	for(;it!=endit;++it)
	{
		if((*it)->getState()==Enemy::ES_NORMAL)
		{
			return false;
		}
	}

	return true;

}

//--------------------------------------------------------------------------
bool  EnemyQueue::isEnemyAllKilled() const 
{

///������˶�����Ķ���ȫ���ˡ���ʾ���ӱ�����
	EnemyCollect::const_iterator it=m_ElemyCollect.begin();
	EnemyCollect::const_iterator endit=m_ElemyCollect.end();
	for(;it!=endit;++it)
	{
		if((*it)->getState()==Enemy::ES_NORMAL||(*it)->getState()==Enemy::ES_SWALLOWBALL)
		{
			return false;
		}
	}

	return true;

}


void EnemyQueue::startLove()
{
	///����ʾ������ 
	EnemyCollect::iterator it=m_FriendCollect.begin();
	EnemyCollect::iterator endit=m_FriendCollect.end();
	for(;it!=endit;++it)
	{
		if((*it)->getState()==Enemy::ES_NORMAL) ///����δ�����е�Ŀ��ʾ��
		{
			(*it)->playAnimation(g_idleAni,true,1.0f);
		}

	}

	return ;
}

///-------------------------------------------------------------------------
void EnemyQueue::startRunaway()
{

	bool leftRotate=false;
	size_t size=m_ElemyCollect.size();
	for(size_t i=0;i<size;++i)
	{
		if(m_ElemyCollect[i]->getState()==Enemy::ES_NORMAL&&m_ElemyCollect[i]->hasActive()==false)
		{
			m_ElemyCollect[i]->startRunAway(1.5f,leftRotate);
			leftRotate=!leftRotate;
		}

	}
	return ;
}


//--------------------------------------------------------------------------
void EnemyQueue::updateThankState(float time)
{

	///ʾ��������ԭ����ʧ��
	m_currentLeftTime+=time;
	if(m_currentLeftTime>3.0)
	{
		m_State=EQ_DISACTIVE;
		///֪ͨɱ��һ�ӵ���
	}


	return ;
}



//--------------------------------------------------------------------------
void EnemyQueue::updateLevelState(float time)
{

	///�������ʧ
	m_currentLeftTime+=time;
	if(m_currentLeftTime>3.0f)
	{
		m_State=EQ_DISACTIVE;

		if(isHitAllEnemy()==false&&hasFriendKilled()==false)
		{
			WarManager::getSingleton().notifyEnemyQueuLost(this);
		}

	}


	return ;

}


//------------------------------------------------------------------
void  EnemyQueue::updateLove(float time)
{

	return ;

}

//------------------------------------------------------------------
void EnemyQueue::updateSwallowBall(float time)
{
	///�������ʧ
	m_currentLeftTime+=time;
	if(m_currentLeftTime>3.0f)
	{
		m_State=EQ_DISACTIVE;
	}



	return ;
}

//------------------------------------------------------------------
void EnemyQueue::updateNormal(float time)
{
    m_currentLeftTime+=time;
    if(m_currentLeftTime>=m_leftTime)
    {
        m_State=EQ_RUNAWAY;
		m_currentLeftTime=0.0f;
		startRunaway();
		return ;
    }
    
}