/**************************************************
���������Ķ���
***************************************************/


#pragma  once


#include "enemy.h"
#include "EventManager.h"

class Enemy;


typedef std::vector<Ogre::Vector3> PositionList;
typedef std::vector<Enemy*> EnemyCollect;///



class EnemyQueue :public CEventManager
{

public:

	EnemyQueue(const  PositionList&EnemyList,const PositionList& FriendList );

	~EnemyQueue();


	/**ÿ֡ѭ��*/
	void update(float time);






protected:

	/**�ж��Ƿ��������ײ
    *@param ray ��������ײ������
	*@param length �����ײ�㳤������
	*@return ����������ཻ�����棬δ���з��ؼ�
	*/
	bool intersectRay(const Ogre::Ray& ray,float length);


	/**��������*/
	void destroy();



protected:



	Ogre::SceneManager*         m_pSceneMrg;      ///����������
	Ogre::SceneNode*            m_pRootNode;

	EnemyCollect                m_ElemyCollect; ///��Ҫ����Ķ����б�
	EnemyCollect                m_FriendCollect;///���ܴ���Ķ����б�










};
