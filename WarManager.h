//
//  WarManager.h
//  ogreApp
//
//  Created by thcz on 11-6-21.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//


#ifndef WarManager_h_h_h_h
#define WarManager_h_h_h_h


#include <vector>
//#include  "enemy.h"

class Bullet;
class Enemy;
class EnemyQueue;


typedef std::vector<Bullet*> BulletCollect;
typedef std::vector<Enemy*> EnemyCollect;


///ս���������ò���ȡ��ս���¼�
class WarListener
{
public:
	WarListener(){};
	virtual ~WarListener(){};


	///��ʼս��
	//virtual void onWarStart()=0;

	///����ս��
	//virtual void onWarEnd()=0;



	///ɱ��һ�ӵ���
	virtual void onKillEnemyQueue(EnemyQueue* pEnemyQueue)=0;

	///��������
	virtual void onLostEnemyQueue(EnemyQueue* pEnemyQueue)=0;


	///����һ���µĵ��˶���
	virtual void onCrateEnemyQueue(EnemyQueue* pEnemyQueue)=0;

};


typedef std::vector<WarListener*>WarListenerCollect;


class WarManager :public Ogre::Singleton<WarManager>
{
public:
    
    /**
      *@param pCameraNode �ӵ������
      */
    WarManager();
    
    ~WarManager();
    
    /*��ʼ��*/
    void init();
    
    
    /**�����ӵ�*/
    void fire(const Ogre::Vector3& pos,const Ogre::Vector3& dir);

	/**�ӵ�ǰ�������λ�÷����ӵ�*/
	void fire();
    
    
    void update(float time);
    
    
    ///�ж���Ϸ�Ƿ����
    bool isGameEnd();
    
    
    ///ս����ʼ
    void startWar();
    
    ///ս������
    void endWar();
    

	/**��ָ���ķ�Χ���������һ��Ŀ�����
	*@param xangle �����x������xangle�Ƕȷ�Χ����,�Ƕ�ֵ
	*@param yangle �����y������yangle�Ƕȷ�Χ����
	%@return ���ش�����Ŀ����С�ʧ�ܷ���NULL
	*/
	EnemyQueue* createEnemyQueue(float xangle,float yangle,const std::vector<Ogre::Vector3>& enemyList,
		const std::vector<Ogre::Vector3>& friendList);



	/**���һ��������
	*/
	void addListener(WarListener* pwarListen);


	/**�Ƴ�һ��������,
	*@remark ֻ�Ƴ���ɾ��
	*/
    void removeListener(WarListener* pWarListen);


	/**�ص�����һ�ӵ�������
	*�ڲ�֪ͨ��������Ҫ��������
	*/
	void notifyEnemyQueuDeath(EnemyQueue* pEnemyQueue);


	/**�ڲ�֪ͨ��������������
	*�ڲ���������Ҫ��������
	*/
	void notifyEnemyQueuLost(EnemyQueue* pEnemyQueue);

    
public:



	///�����ײ
	bool intersectEnemy(Bullet* pBullet);

	///��ײ���
	void intersectEnemyQueue(Bullet* pBullet);

    
    ///@{
    
    ///����һ������
    Enemy* createEnemy(const Ogre::Vector3& pos);
    
    
    ///ͨ��ogre entityName��ȡ��enemyָ��
    Enemy* getEnemyByEntityName(const std::string& name) const ;


protected:
    
    ///�������еĵ���
    void  destroyAllEnemy();
    
    ///ÿ֡���µ���
    void  updateEnemy(float time);

	void updateEnemyQueue(float time);
    
    ///���������ص�
    void  hasEnemyDeath(Enemy* pEnemy);
    
    ///��ȡһ����������λ�����û�з��ؿ�
    Enemy* getDeathEnemy();
    
    
	
    ///@}
    
protected:
    
    void destroyAllBullet();

	/**�������еĶ���*/
	void destroyAllEnemyQueue();
    
    /**��ȡһ��׼���õ��ӵ�,���û�з��ؿ�*/
    Bullet*  getBullet();

	///�㲥ɱ��������Ϣ
	void fireKillEnemyQueue(EnemyQueue* pQueue);

	///�㲥����������Ϣ
	void fireLostEnemyQueue(EnemyQueue* pQueue);

	///�㲥�����µ�����Ϣ
	void fireCreateEnemyQueue(EnemyQueue* pQueue);
     
    
protected:
    
    
      
    float         m_FireTime;///��������
    
    float         m_LastFireTime;///��һ�ŵķ���ʱ��
    
    
    BulletCollect      m_BulletCollect;///�����ӵ�����
  
    EnemyCollect       m_EnemyCollect;///����Ŀ��ļ���

	typedef std::vector<EnemyQueue*> EnemyQueueCollect;
	EnemyQueueCollect m_EnemyQueueCollect;

	EnemyQueueCollect  m_DeleteEnemyQueueCollect;
    
    Ogre::SceneManager*   m_pSceneMrg;
    bool                  m_GameBegan;


	WarListenerCollect    m_listenerCollect;  ///����������
    
};






#endif