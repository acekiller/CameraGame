//
//  WarManager.cpp
//  ogreApp
//
//  Created by thcz on 11-6-21.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//
#include "pch.h"
#include "WarManager.h"
#include  "Bullet.h"
#include  "Application.h"
#include  "enemy.h"
#include "Config.h"
#include "EnemyQueue.h"
#include "Application.h"

namespace Ogre 
{
template<> WarManager* Ogre::Singleton<WarManager>::ms_Singleton=NULL;
}



//---------------------------------------------------
WarManager::WarManager()
:m_pSceneMrg(NULL),m_Flag(0)
{
    
    m_pSceneMrg=Application::getSingleton().getMainSceneManager();

}

//---------------------------------------------------
WarManager::~WarManager()
{
    destroyAllBullet();
    destroyAllEnemy();

	destroyAllEnemyQueue();


}


//---------------------------------------------------
void WarManager::init()
{

	destroyAllBullet();

    for(int i=0; i<10; ++i)
    {
        m_BulletCollect.push_back(new Bullet(m_pSceneMrg));
    }
    
       
}

//---------------------------------------------------
void WarManager::fire()
{
	Bullet* pBullet=getBullet();
	if(pBullet==NULL)
		return ;
	Ogre::SceneNode* pCameraNode=Application::getSingleton().getMainCamera()->getParentSceneNode();
	Ogre::Matrix3 matrix= pCameraNode->getLocalAxes();
	Ogre::Vector3  pos=pCameraNode->getPosition();


	Ogre::Vector3 dir(matrix[0][2],matrix[1][2],matrix[2][2]);
	dir.normalise();
	pos-=dir*2;
	pos.y-=0.5f;

	dir.y-=0.15f;
	dir.normalise();

	///�ӵ�����ʱ�������Ϸ���һ��
	//dir.y-=0.15;
	//dir.normalise();
	fire(pos,dir);

}


//---------------------------------------------------
void WarManager::fire(const Ogre::Vector3& pos,const Ogre::Vector3& dir)
{
    Bullet* pBullet=getBullet();
    if(pBullet!=NULL)
    {
        pBullet->shoot(pos, dir);
	    notifyFire(pBullet);
    }
    
    return ;
    
}

//---------------------------------------------------
void WarManager::update(float time)
{
    
	///����Ѿ���������Ϣ
	if(hasFlag(F_EndWar))
	{
		_endWar();
		return ;
	}
  
	//�����ս���С�
	if(hasFlag(F_InWar)==false)
		return ;




    ///�������е��ӵ�
    size_t size=m_BulletCollect.size();
	Ogre::Ray ray;
	float rayLenght=0.0f;
    for(size_t i=0;i<size;++i)
    {
		///����ӵ��Ƿ���״̬������ײ���
		if(m_BulletCollect[i]->update(time)&&m_BulletCollect[i]->getState()==Bullet::BS_SHOOT)
		{
			intersectEnemyQueue(m_BulletCollect[i]);

		}


    }
    
    
    updateEnemy(time);
	updateEnemyQueue(time);
    
    return ;
}


//---------------------------------------------------
void WarManager::destroyAllBullet()
{
    size_t size=m_BulletCollect.size();
    for(size_t i=0;i<size;++i)
    {
        delete m_BulletCollect[i];
    }
    
    m_BulletCollect.clear();
}

//--------------------------------------------------
void WarManager::destroyAllEnemyQueue()
{

	size_t size=m_EnemyQueueCollect.size();
	for(size_t i=0;i<size;++i)
	{
      delete m_EnemyQueueCollect[i];
	}
	m_EnemyQueueCollect.clear();







}

//---------------------------------------------------
Bullet* WarManager::getBullet()
{
    size_t size=m_BulletCollect.size();
    for(size_t i=0;i<size;++i)
    {
        if(m_BulletCollect[i]->getState()==Bullet::BS_NONE)
        {
            return m_BulletCollect[i];
        }
    }
    
    return NULL;

}


//---------------------------------------------------
bool  WarManager::intersectEnemy(Bullet* pBullet)
{
	EnemyCollect::iterator it=m_EnemyCollect.begin();
	EnemyCollect::iterator itend=m_EnemyCollect.end();

	for(;it!=itend;++it)
	{
	//	//if((*it)->intersectRay(ray,lenght))
		//	return true;
	}
	 
	return false;

}

void  WarManager::intersectEnemyQueue(Bullet* pBullet)
{

	EnemyQueueCollect::iterator it=m_EnemyQueueCollect.begin();
	EnemyQueueCollect::iterator itend=m_EnemyQueueCollect.end();

	for(;it!=itend;++it)
	{
		(*it)->updateCollision(pBullet);
	}

	return ;

}

//---------------------------------------------------
Enemy* WarManager::createEnemy(const Ogre::Vector3& pos)
{
    
   // for(int i=-5;i<5;++i)
  
      //  for(int j=-5;j<5;++j)
     
            //Ogre::Vector3 temPos(i,j,0);
			Ogre::Vector3 temPos=pos;
			const Ogre::String& faceMesh=g_userInformation.getFaceMode();
			const Ogre::String& headMesh=g_userInformation.getHeadMode();
            Enemy* pEnemy=  new Enemy(faceMesh,headMesh,temPos,m_pSceneMrg->getRootSceneNode());
            pEnemy->reset(temPos);
            
            m_EnemyCollect.push_back(pEnemy);

 
    
    return pEnemy;
}


//---------------------------------------------------
Enemy* WarManager::getEnemyByEntityName(const std::string& name) const 
{
    EnemyCollect::const_iterator it=m_EnemyCollect.begin();
    EnemyCollect::const_iterator endit=m_EnemyCollect.end();
    
    for(;it!=endit;++it)
    {
        if( (*it)->getEntityName()==name)
        {
            return *it;
        }
    }
    
    return NULL;
}

//---------------------------------------------------
void  WarManager::destroyAllEnemy()
{
    EnemyCollect::const_iterator it=m_EnemyCollect.begin();
    EnemyCollect::const_iterator endit=m_EnemyCollect.end();
    
    for(;it!=endit;++it)
    {
        delete (*it);
    }
    m_EnemyCollect.clear();
    return ;
}


//----------------------------------------------
void  WarManager::updateEnemy(float time)
{
    EnemyCollect::const_iterator it=m_EnemyCollect.begin();
    EnemyCollect::const_iterator endit=m_EnemyCollect.end();
    
    for(;it!=endit;++it)
    {
        (*it)->update(time);
    }
    return ;
}

//----------------------------------------------
void  WarManager::hasEnemyDeath(Enemy* pEnemy)
{
   // pEnemy->reset(Ogre::Vector3(0,0,0));
    return ;
}

//------------------------------------------------
bool WarManager::isGameEnd()
{
    
    return !hasFlag(F_InWar);
    
}

//-------------------------------------------------
void WarManager::startWar()
{

    addFlag(F_InWar);
	init();

    return ;
}

//------------------------------------------------
void WarManager::endWar()
{

	addFlag(F_EndWar);
    removeFlag(F_InWar);
 
    return ;
}

//---------------------------------------------------
Enemy* WarManager::getDeathEnemy()
{
    
    EnemyCollect::iterator it=m_EnemyCollect.begin();
    EnemyCollect::iterator endit=m_EnemyCollect.end();
    for(;it!=endit;++it)
    {
        if((*it)->getState()==Enemy::ES_DEATH)
        {
            return *it;
        }
    }
    
    return NULL;
}


//---------------------------------------------------------
void WarManager::notifyEnemyQueuDeath(EnemyQueue* pEnemyQueue)
{
	fireKillEnemyQueue(pEnemyQueue);
	///����һ���µĶ���

	m_DeleteEnemyQueueCollect.push_back(pEnemyQueue);

	return ;

}

//---------------------------------------------------------
void WarManager::notifyEnemyQueuLost(EnemyQueue* pEnemyQueue)
{
	fireLostEnemyQueue(pEnemyQueue);
	
	///������������ϵĵ���
	m_DeleteEnemyQueueCollect.push_back(pEnemyQueue);

	return ;

}

//---------------------------------------------------------
/**�ڲ�������֪ͨ�����˲�Ӧ���е�Ŀ��*/
void WarManager::notifyHitFriend(Enemy* pEnemy)
{

	WarListenerCollect::iterator it=m_listenerCollect.begin();
	WarListenerCollect::iterator itend=m_listenerCollect.end();

	for(;it!=itend;++it)
	{
		(*it)->onHitFriend(pEnemy);
	}
	return ;



}
//----------------------------------------------------------------
void WarManager::notifyFire(Bullet* pBullet)
{

	WarListenerCollect::iterator it=m_listenerCollect.begin();
	WarListenerCollect::iterator itend=m_listenerCollect.end();

	for(;it!=itend;++it)
	{
		(*it)->onfire(pBullet);
	}

}



//----------------------------------------------------------------
void WarManager::notifyKillEnemy(Enemy* pEnemy,bool hitMouth,Bullet* pBullet)
{

	WarListenerCollect::iterator it=m_listenerCollect.begin();
	WarListenerCollect::iterator itend=m_listenerCollect.end();

	for(;it!=itend;++it)
	{
		(*it)->onHitEnemy(pEnemy,hitMouth,pBullet);
	}
	return ;	

}

//---------------------------------------------------------

EnemyQueue* WarManager::createEnemyQueue(float minxangle,float maxxangle,float minyangle,float maxyangle,float mindis,float maxdis,
							  const  std::vector<Ogre::Vector3>& enemyList,
							 const std::vector<Ogre::Vector3>& friendList)

{
	Ogre::Camera* pCamera=Application::getSingleton().getMainCamera();

	
	float xangle=Ogre::Math::RangeRandom(minxangle,maxxangle);
	float yangle=Ogre::Math::RangeRandom(minyangle,maxyangle);
	float zdis=  Ogre::Math::RangeRandom(mindis,maxdis);


	 Ogre::Radian xRadian=Ogre::Degree(xangle);
	 Ogre::Radian yRadian=Ogre::Degree(yangle);

	 float x=Ogre::Math::Sin(xRadian.valueRadians());
	 float z=Ogre::Math::Cos(xRadian.valueRadians());
	 float y=Ogre::Math::Sin(yRadian.valueRadians());


	 Ogre::Vector3 pos(x,y,z);
	 pos.normalise();
	 pos*=zdis;

	 pos+=pCamera->getParentSceneNode()->getPosition();
	
	 EnemyQueue* pQueue=new EnemyQueue(pos,enemyList,friendList);
     m_EnemyQueueCollect.push_back(pQueue);

	 fireCreateEnemyQueue(pQueue);

	 return pQueue;

}

//---------------------------------------------------------
void  WarManager::updateEnemyQueue(float time)
{

	///�Ȱ���Ҫɾ���Ķ�ɾ��
	if(m_DeleteEnemyQueueCollect.empty()==false)
	{
		EnemyQueueCollect::iterator deleteIt=m_DeleteEnemyQueueCollect.begin();
		EnemyQueueCollect::iterator deleteEndIt=m_DeleteEnemyQueueCollect.end();
		for(;deleteIt!=deleteEndIt;++deleteIt)
		{
			EnemyQueueCollect::iterator temIt=std::find(m_EnemyQueueCollect.begin(),m_EnemyQueueCollect.end(),(*deleteIt));
			if(temIt!=m_EnemyQueueCollect.end())
			{
				delete (*temIt);
				m_EnemyQueueCollect.erase(temIt);
				
			}

		}
		m_DeleteEnemyQueueCollect.clear();

	}



	EnemyQueueCollect::iterator it=m_EnemyQueueCollect.begin();
	EnemyQueueCollect::iterator endit=m_EnemyQueueCollect.end();
	for(;it!=endit;++it)
	{
		(*it)->update(time);
	}

	return ;

}

//---------------------------------------------------------
void WarManager::addListener(WarListener* pwarListen)
{
	if(pwarListen==NULL)
		return ;
	///����Ѿ������˾Ͳ��ټ���
	WarListenerCollect::iterator it=m_listenerCollect.begin();
	WarListenerCollect::iterator itend=m_listenerCollect.end();

	for(;it!=itend;++it)
	{
		if((*it)==pwarListen)
		{
			return ;
		}
	}

	m_listenerCollect.push_back(pwarListen);
	return ;

}


//----------------------------------------------------------------
void WarManager::removeListener(WarListener* pWarListen)
{
	if(pWarListen==NULL)
		return ;
	
	WarListenerCollect::iterator it=m_listenerCollect.begin();
	WarListenerCollect::iterator itend=m_listenerCollect.end();

	for(;it!=itend;++it)
	{
		if((*it)==pWarListen)
		{
			m_listenerCollect.erase(it);
			return ;
		}
	}

	return ;
}

//----------------------------------------------------------------
void WarManager::fireKillEnemyQueue(EnemyQueue* pQueue)
{

	WarListenerCollect::iterator it=m_listenerCollect.begin();
	WarListenerCollect::iterator itend=m_listenerCollect.end();

	for(;it!=itend;++it)
	{
	  (*it)->onKillEnemyQueue(pQueue);
	}


	return ;

}



//----------------------------------------------------------------
void WarManager::fireLostEnemyQueue(EnemyQueue* pQueue)
{
	WarListenerCollect::iterator it=m_listenerCollect.begin();
	WarListenerCollect::iterator itend=m_listenerCollect.end();

	for(;it!=itend;++it)
	{
		(*it)->onLostEnemyQueue(pQueue);
	}
	return ;

}

//----------------------------------------------------------------
void  WarManager::fireCreateEnemyQueue(EnemyQueue* pQueue)
{

	WarListenerCollect::iterator it=m_listenerCollect.begin();
	WarListenerCollect::iterator itend=m_listenerCollect.end();

	for(;it!=itend;++it)
	{
		(*it)->onCrateEnemyQueue(pQueue);
	}
	return ;



}