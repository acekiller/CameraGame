//
//  Bullet.h
//  ogreApp
//
//  Created by thcz on 11-6-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//
#ifndef Bullet_h_h_h_h_
#define Bullet_h_h_h_h_


#include  "enemy.h"


class Bullet
{
    
   // friend class WarManager;
    protected:
    
    public:
    
    enum BulletState
    {
      BS_NONE,    //隐藏状态
      BS_SHOOT,  //发射状态
	  BS_REFLECT,//击中后反弹状态
    };

    
    Bullet(Ogre::SceneManager* pSceneMrg);
    
    ~Bullet();
    
    
      
  public:  

    ///每帧更新,如果是发射状态返回真。非发射状态返回假
    bool  update(float time);
    
    /**发射子弹
       *@param position，发射的初始位置，
       *@param dir    子弹的发射的方向，需要归一化向量
       */
    void shoot(const Ogre::Vector3& position, const Ogre::Vector3& dir);
    
    
    void setliftTime(float time){m_LiftTime=time;}

    
    BulletState getState()const {return m_State;}

	/**返回上一帧时间度的射线和长度*/
	bool getFrameRay(Ogre::Ray& ray,float& lenght);



	/**设置击中标记,计算反射*/
	void hitTarget();


	/**设置子弹的方向*/
	void setBulletDir(const Ogre::Vector3& dir){m_Dir=dir;}


	/**设置是否可见*/
	void setVisible(bool b);

    
    protected:
    
    /**销毁*/
    void destroy();
    
    /**重置*/
    void reset();
protected:  
    
    /**判断是否击中目标
     *@param dir 子弹飞行的方向
     *@param length 子弹在一帧内分行的长度
     *@warning 只做外框盒检查
     */
  //  void updateHit(const Ogre::Vector3& pos,const Ogre::Vector3& dir,float length);    
    
    
    
    
protected:
    Ogre::Entity*      m_pEntity;
    Ogre::SceneNode*   m_pNode;
    Ogre::Vector3     m_Gravity;///子弹的重力
    
    Ogre::Vector3     m_OrigiPosition;
    Ogre::Vector3     m_Dir;///子弹发射方向
    float         m_Force; ///动力
    float         m_LiftTime;///生命周期 
    float         m_CurrentTime;///当前生命时期 
    float         m_Speed; ///子弹的速度
    
    Ogre::SceneManager*  m_pSceneMrg;
   // Ogre::RaySceneQuery*  m_pRayQuery;
    
    BulletState      m_State;
	Ogre::Ray        m_ray;
	float            m_raylenght;
	
    
    
       
};






#endif