/**************************************************
���������Ķ���
***************************************************/


#pragma  once


#include "enemy.h"
#include "EventManager.h"

class Enemy;


typedef std::vector<Ogre::Vector3> PositionList;
typedef std::vector<Enemy*> EnemyCollect;///



class EnemyQueue : public CEventManager
{

public:

	enum EQST
	{
    //  EQ_NORMAl,//����״̬
	 // EQ_
	};


public:

	EnemyQueue(const Ogre::Vector3& pos,const  PositionList&EnemyList,const PositionList& FriendList );

	~EnemyQueue();


	/**ÿ֡ѭ��*/
	void update(float time);

	/**��ȡ�������ڵ�����ڵ�*/
	Ogre::SceneNode* getSceneNode()const {return m_pRootNode;}

	/**������ײ���*/
	void updateCollision(Bullet* pBullet);


	/**��ȡ������������*/
	Ogre::AxisAlignedBox getWordBox();


protected:

	
	/**�ж��Ƿ��������ײ
    *@param ray ��������ײ������
	*@param length �����ײ�㳤������
	*@return ����������ཻ�����棬δ���з��ؼ�
	*/
	// bool intersectRay(const Ogre::Ray& ray,float length);
	


	/**��������*/
	void destroy();


	/**��������֪ͨ*/
	void notifyEnemyDeath(Enemy* pEnemy);


	/**�Ƿ��ж��Ѷ��񱻴���*/
	bool  hasFriendKilled();

	/**���е����Ƿ񶼱�����*/
	bool  isEnemyAllKilled();


protected:



	Ogre::SceneManager*         m_pSceneMrg;      ///����������
	Ogre::SceneNode*            m_pRootNode;

	EnemyCollect                m_ElemyCollect; ///��Ҫ����Ķ����б�
	EnemyCollect                m_FriendCollect;///���ܴ���Ķ����б�










};
