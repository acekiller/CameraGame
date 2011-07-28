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
      EQ_NORMAl,//����״̬
	  EQ_KILLALLENEMY,///���е��˱�����
	  EQ_KILLFRIEND,//ɱ�������ˡ�

	  EQ_DISACTIVE,//�ǻ״̬
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

	/**���¸�л״̬����Ϣ*/
	void updateThankState(float time);



	/**��������״̬*/
	void updateLevelState(float time);
    
    /**����״̬����*/
    void updateNormal(float time);

	
	/**�ж��Ƿ��������ײ
    *@param ray ��������ײ������
	*@param length �����ײ�㳤������
	*@return ����������ཻ�����棬δ���з��ؼ�
	*/
	// bool intersectRay(const Ogre::Ray& ray,float length);
	


	/**��������*/
	void destroy();


	/**���˱�����֪ͨ*/
	void notifyEnemyHit(Enemy* pEnemy);


	/**�Ƿ��ж��Ѷ��񱻴���*/
	bool  hasFriendKilled();

	/**���е����Ƿ񶼱�����*/
	bool  isEnemyAllKilled();


protected:



	Ogre::SceneManager*         m_pSceneMrg;      ///����������
	Ogre::SceneNode*           m_pRootNode;

	EnemyCollect             m_ElemyCollect; ///��Ҫ����Ķ����б�
	EnemyCollect             m_FriendCollect;///���ܴ���Ķ����б�

	EQST                   m_State;
	float                  m_loveTime;       ///ʾ��ʱ��
	Ogre::Vector3              m_LevelPoint;      ///�ɵ�Ļ���Ŀ���
    








};
