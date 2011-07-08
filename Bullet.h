//
//  Bullet.h
//  ogreApp
//
//  Created by thcz on 11-6-21.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//
#ifndef Bullet_h_h_h_h_
#define Bullet_h_h_h_h_


#include  "enemy.h"


class Bullet
{
    
    friend class BulletManager;
    protected:
    
    public:
    
    enum BulletState
    {
      BS_NONE,
      BS_SHOOT,
    };

    
    Bullet(Ogre::SceneManager* pSceneMrg);
    
    ~Bullet();
    
    
      
  public:  
    ///ÿ֡����
    void update(float time);
    
    /**�����ӵ�
       *@param position������ĳ�ʼλ�ã�
       *@param dir    �ӵ��ķ���ķ�����Ҫ��һ������
       */
    void shoot(const Ogre::Vector3& position, const Ogre::Vector3& dir);
    
    
    void setliftTime(float time){m_LiftTime=time;}

    
    BulletState getState()const {return m_State;}
    
    protected:
    
    /**����*/
    void destroy();
    
    /**����*/
    void reset();
    
    
protected:  
    
    /**�ж��Ƿ����Ŀ��
     *@param dir �ӵ����еķ���
     *@param length �ӵ���һ֡�ڷ��еĳ���
     *@warning ֻ�����м��
     */
    void updateHit(const Ogre::Vector3& pos,const Ogre::Vector3& dir,float length);    
    
    
    
    
protected:
    Ogre::Entity*      m_pEntity;
    Ogre::SceneNode*   m_pNode;
    Ogre::Vector3     m_Gravity;///�ӵ�������
    
    Ogre::Vector3     m_OrigiPosition;
    Ogre::Vector3     m_Dir;///�ӵ����䷽��
    float         m_Force; ///����
    float         m_LiftTime;///�������� 
    float         m_CurrentTime;///��ǰ����ʱ�� 
    float         m_Speed; ///�ӵ����ٶ�
    
    Ogre::SceneManager*  m_pSceneMrg;
    Ogre::RaySceneQuery*  m_pRayQuery;
    
    BulletState      m_State;
    
    
       
};






#endif