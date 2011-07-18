//
//  enemy.h
//  ogreApp
//
//  Created by thcz on 11-6-27.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//


#pragma once

class Bullet;


#define EnemyMask 0x0100



class Enemy
{
    
public:
    
    enum EnemyState
    {
        ES_NORMAL, ///���֣�δ����ʱ״̬
        ES_DODGE, ////���˺���
        ES_DEATH, ///����״̬
    };
    
    
    
    public:
    
    /**���캯��
     *@param meshName mesh�ļ���
     *@param pos     ���ֵĳ�ʼλ
     */
    Enemy(const Ogre::String& meshName,const Ogre::Vector3&  pos, Ogre::SceneManager* pSceneMrg);

    
    ~Enemy();
    
    
    
    /**������ʱ�Ļص�
     *@param hitPos ���еĵ�
     *@param pBullet ���е��ӵ�
     */
    virtual void onHit(const Ogre::Vector3& hitPos,Bullet* pBullet );
    
    
    ///
    void setVisible(bool b);
    
    
    ///
    void update(float time);
    
    
    
    ///��ȡ����
    const std::string& getEntityName()const;
    
    
    ///��ȡ����ֵ
    float getLeftValue()const{return m_LeftValue;}
        
    ///��������ֵ
    void  setLeftValue(float value){m_LeftValue=value;}

    
    ///����,��ָ����λ�����³���
    void reset(const Ogre::Vector3& pos);
    
    ///��ȡ״̬
    EnemyState getState()const {return m_State;}    

protected:
    
    ///����
    void death();
    
    ///����
    void destroy();
    
    
    ///���³���ʱ
    void updateNormal(float time);
    
    ///
    void updateDodge(float time);
    
    ///
    void updateDeath(float time);
    
    
    
    Ogre::Entity*     m_pEntity;
    Ogre::SceneNode*  m_pNode;
    Ogre::SceneManager* m_pSceneMrg;
    
    
    Ogre::AnimationState* m_pAniSate;
    
    static int     m_EntityIndex;
    
    
    float        m_LeftValue;///����ֵ
    
    EnemyState      m_State;///״̬
    
    
    ///�����к����ת 
    float         m_Rotate;
    
    ///�����к����ĸ������˶���
    Ogre::Vector3     m_Trans;
    
    Ogre::MaterialPtr    m_pMaterial;


	Ogre::Entity*        m_pHeadEnity;
    
    
    
};