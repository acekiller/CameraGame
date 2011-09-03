/**************************************************
���������Ķ���
***************************************************/


#pragma  once


#include "enemy.h"
#include "EventManager.h"

class Enemy;


typedef std::vector<Ogre::Vector3> PositionList;
typedef std::vector<Enemy*> EnemyCollect;///



class EnemyQueue : public CEventManager ,public ActiveContainer
{

public:

	enum EQST
	{
      EQ_NORMAl,         //����״̬
	//  EQ_LOVE,             //ʾ��
	  EQ_RUNAWAY,          //����
	  EQ_SWALLOWBALL,      ///����
	  EQ_DISACTIVE,      //�������ڽ���
	};


public:

	EnemyQueue(const Ogre::Vector3& pos,const  PositionList&EnemyList,const PositionList& FriendList );

	~EnemyQueue();


	/**ÿ֡ѭ��*/
    EQST   update(float time);

	/**��ȡ�������ڵ�����ڵ�*/
	Ogre::SceneNode* getSceneNode()const {return m_pRootNode;}

	/**������ײ���*/
	void updateCollision(Bullet* pBullet);


	/**��ȡ������������*/
	Ogre::AxisAlignedBox getWordBox();

	/**��ȡ��������*/
	float getLeftTime()const{return m_leftTime;}

	/**������������*/
	void  setLeftTime(float time){m_leftTime=time;}

	

protected:

	/**��ʼ����*/
	void startRunaway();

	/**��ʼʾ��*/
	void startLove();


	/**���¸�л״̬����Ϣ*/
	void updateThankState(float time);


	/**��������״̬*/
	void updateLevelState(float time);
    
    /**����״̬����*/
    void updateNormal(float time);

	
	/**����ʾ��*/
	void updateLove(float time);

	/**���º���״̬*/
	void updateSwallowBall(float time);

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
	bool  hasFriendKilled() const ;

	/**���е����Ƿ񶼱�����*/
	bool  isEnemyAllKilled() const ;

	/**�Ƿ����е��˶�������*/
	bool  isHitAllEnemy() const ;
             
	/**�Ƿ��к���״�ĵ�Ŀ��*/
	bool  hasSwallowBallEnemy()const;


protected:



	Ogre::SceneManager*         m_pSceneMrg;      ///����������
	Ogre::SceneNode*           m_pRootNode;

	EnemyCollect             m_ElemyCollect; ///��Ҫ����Ķ����б�
	EnemyCollect             m_FriendCollect;///���ܴ���Ķ����б�

	EQST                       m_State;
	float                      m_currentLeftTime;       ///��ǰ����ֵ
	//Ogre::Vector3              m_LevelPoint;      ///�ɵ�Ļ���Ŀ���
	float                      m_leftTime;        ///��������
    








};
