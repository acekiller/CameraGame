//
//  WarManager.cpp
//  ogreApp
//
//  Created by thcz on 11-6-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
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
:m_pSceneMrg(NULL),m_GameBegan(false)
{
    
    m_pSceneMrg=Application::getSingleton().getMainSceneManager();
    init();
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
	pos-=dir*4;

	///子弹发送时稍稍向上发送一点
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
    }
    
    return ;
    
}

//---------------------------------------------------
void WarManager::update(float time)
{
    
    if(m_GameBegan==false)
    {
        return ;
    }

    ///更新所有的子弹
    size_t size=m_BulletCollect.size();
	Ogre::Ray ray;
	float rayLenght=0.0f;
    for(size_t i=0;i<size;++i)
    {
		///如果子弹是发射状态就做碰撞检测
        if(m_BulletCollect[i]->update(time))
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
    {
      //  for(int j=-5;j<5;++j)
        {
            //Ogre::Vector3 temPos(i,j,0);
			Ogre::Vector3 temPos=pos;
			const Ogre::String& faceMesh=g_userInformation.getFaceMode();
			const Ogre::String& headMesh=g_userInformation.getHeadMode();
            Enemy* pEnemy=  new Enemy(faceMesh,headMesh,temPos,m_pSceneMrg->getRootSceneNode());
            pEnemy->reset(temPos);
            
            m_EnemyCollect.push_back(pEnemy);

            
        }
    }
    
    
       
    return m_EnemyCollect[0];
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
    
    return !m_GameBegan;
    
}

//-------------------------------------------------
void WarManager::startWar()
{
    m_GameBegan=true;

   // WarManager::getSingleton().createEnemy(Ogre::Vector3(0,0,0));

    return ;
}

//------------------------------------------------
void WarManager::endWar()
{
    m_GameBegan=false;

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
///回调函数一队敌人死亡
void WarManager::notifyEnemyQueuDeath(EnemyQueue* pEnemyQueue)
{

	return ;

}


EnemyQueue* WarManager::createEnemyQueue(float xangle,float yangle)
{
	Ogre::Camera* pCamera=Application::getSingleton().getMainCamera();

	 xangle=Ogre::Math::RangeRandom(-xangle,xangle);
	 yangle=Ogre::Math::RangeRandom(-yangle,yangle);


	 Ogre::Radian xRadian=Ogre::Degree(xangle);
	 Ogre::Radian yRadian=Ogre::Degree(yangle);

	 float x=Ogre::Math::Sin(xRadian.valueRadians());
	 float z=Ogre::Math::Cos(xRadian.valueRadians());
	 float y=Ogre::Math::Sin(yRadian.valueRadians());


	 Ogre::Vector3 pos(x,y,z);
	 pos.normalise();
	 pos.x*=5.0f;
	 pos.y*=5.0f;
	 pos.z=-10;

	 PositionList Enemylist;
     Enemylist.push_back(Ogre::Vector3(2.0f,0.0f,0.0f));
	 Enemylist.push_back(Ogre::Vector3(-2.0f,0.0f,0.0f));

	 PositionList FriendList;
	 FriendList.push_back(Ogre::Vector3(0.0f,0.0f,0.0f));


	 EnemyQueue* pQueue=new EnemyQueue(pos,Enemylist,FriendList);
     m_EnemyQueueCollect.push_back(pQueue);
	 return pQueue;

}

void  WarManager::updateEnemyQueue(float time)
{
	EnemyQueueCollect::iterator it=m_EnemyQueueCollect.begin();
	EnemyQueueCollect::iterator endit=m_EnemyQueueCollect.end();
	for(;it!=endit;++it)
	{
		(*it)->update(time);
	}

	return ;

}