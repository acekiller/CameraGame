//
//  CollisionManager.h
//  ogreApp
//
//  Created by thcz on 11-6-24.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//


#pragma once


#include "btBulletDynamicsCommon.h"

/// �򵥷�װbullet����

class CollisionManager : public Ogre::Singleton<CollisionManager>
{
    
public:
    CollisionManager();
    
    
    ~CollisionManager();
    
    
    /**����һ����������
       *@param radius �뾶
       *@param mass ����
       *@param �󶨵�ogreʵ��
       */
    btRigidBody* createRigidBody(float radius,float mass,Ogre::SceneNode* pNode);
    
    
    
    ///��ʼ��
    void init();
    
    ///�������е���������
    void destroy();
    
    ///ÿ֡����
    void update(float time);
    
    ///��������
    void setGravity(float x,float y, float z);
    
    
    
    
    
    
protected:
    
    
    btDiscreteDynamicsWorld*         m_pDynamicsWorld;
    btCollisionConfiguration*        m_pCollisionConfig;
    btCollisionDispatcher*          m_pCollisionDispatcher;
    btSequentialImpulseConstraintSolver*  m_pConstraintSolver;
    btBroadphaseInterface*          m_pBroadphase;
    
    
    btAlignedObjectArray<btCollisionShape*> m_CollisionShapes;
    btAlignedObjectArray<btRigidBody*>    m_BoxBodies;
    
};