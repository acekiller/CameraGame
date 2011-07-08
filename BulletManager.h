//
//  BulletManager.h
//  ogreApp
//
//  Created by thcz on 11-6-21.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//


#ifndef BulletManager_h_h_h_h
#define BulletManager_h_h_h_h


#include <vector>
//#include  "enemy.h"

class Bullet;
class Enemy;

typedef std::vector<Bullet*> BulletCollect;
typedef std::vector<Enemy*> EnemyCollect;

class BulletManager :public Ogre::Singleton<BulletManager>
{
public:
    
    /**
      *@param pCameraNode �ӵ������
      */
    BulletManager();
    
    ~BulletManager();
    
    /*��ʼ��*/
    void init();
    
    
    /**�����ӵ�*/
    void fire(const Ogre::Vector3& pos,const Ogre::Vector3& dir);
    
    
    void update(float time);
    
    
    ///�ж���Ϸ�Ƿ����
    bool isGameEnd();
    
    
    ///ս����ʼ
    void startWar();
    
    ///ս������
    void endWar();
    
    
    
public:
    
    ///@{
    
    ///����һ������
    Enemy* createEnemy(const Ogre::Vector3& pos);
    
    
    ///ͨ��ogre entityName��ȡ��enemyָ��
    Enemy* getEnemyByEntityName(const std::string& name) const ;
    
    ///�������еĵ���
    void  destroyAllEnemy();
    
    ///ÿ֡���µ���
    void  updateEnemy(float time);
    
    ///���������ص�
    void  hasEnemyDeath(Enemy* pEnemy);
    
    ///��ȡһ����������λ�����û�з��ؿ�
    Enemy* getDeathEnemy();
    
    
    
    ///@}
    
protected:
    
    void destroy();
    
    /**��ȡһ��׼���õ��ӵ�,���û�з��ؿ�*/
    Bullet*  getBullet();
    
    
protected:
    
    
      
    float         m_FireTime;///��������
    
    float         m_LastFireTime;///��һ�ŵķ���ʱ��
    
    
    BulletCollect      m_BulletCollect;///�����ӵ�����
    
    
    EnemyCollect       m_EnemyCollect;///����Ŀ��ļ���
    
    Ogre::SceneManager*   m_pSceneMrg;
    
    
    bool            m_GameBegan;
    
};






#endif