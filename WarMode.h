
#pragma once



/************************************
��Ϸģʽ����
*************************************/

#include "WarManager.h"

class GameState;


class  WarMode
{
public:

	WarMode(GameState* pGameState)
	:m_end(false),m_pGameState(pGameState){}

	virtual ~WarMode(){}

	
	/**��ʼ��Ϸ*/
	virtual void start()=0;

	/**��Ϸ����*/
    virtual	void end()=0;

	/**ÿ֡����*/
	virtual void update(float time)=0;


	/**��������¼�*/
	virtual  void beginTouch(int x,int y){};

	/**����뿪�¼�*/
	virtual void  endTouch(int x,int y){};

	/**����ƶ��¼�*/
	virtual void  moveTouch(int x,int y){}


	/**�ж���Ϸ�Ƿ����*/
	bool    isEnd()const{return m_end;}



protected:

	


	GameState*       m_pGameState;

	bool             m_end;////trueΪ��Ϸ����



};







/***************************************************
��Ϸģʽ2
****************************************************/
class UIWarModeTwo;
class Enemy;
class UIBase;
class WarModeTwo :public WarMode ,public WarListener
{
public:

	///������
	typedef std::vector<Ogre::Vector3> Vector3Collect;
	class EnemyFormat
	{
	public:
		Vector3Collect m_EnemyCollect;
		Vector3Collect m_FriendCollect;
		
	};

	typedef std::vector<EnemyFormat> EnemyFormatCollect;




public:

	WarModeTwo(GameState* pGameState);


	virtual ~WarModeTwo();


	/**��ʼ��Ϸ*/
	virtual void start();

	/**��Ϸ����*/
	virtual	void end();

	/**ÿ֡����*/
	virtual void update(float time);


	/**��������¼�*/
	virtual  void beginTouch(int x,int y);

	/**����뿪�¼�*/
	virtual void  endTouch(int x,int y);

	/**����ƶ��¼�*/
	virtual void  moveTouch(int x,int y);



protected:
	

	///��ʼ������
	void initEmemyFormat();

	///��ʼ��ui��Ϸ��ʼ
	void initUI();

	///����ui
	void destroyUI();


	///ɱ��һ�ӵ���
	virtual void onKillEnemyQueue(EnemyQueue* pEnemyQueue);

	///��������
	virtual void onLostEnemyQueue(EnemyQueue* pEnemyQueue);

	///�����µ���
	virtual void onCrateEnemyQueue(EnemyQueue* pEnemyQueue);


	void createEnemyQueue()
	{
		m_needCreate=true;

	}

	///�ڲ�����������������
	void   _createEnemyQueue();




protected:

	//Enemy* m_pEnemy;

	UIWarModeTwo*           m_pUI;///������ui����
	UIBase*                 m_pUIBalance;///�������
	Ogre::SceneManager*     m_pSceneMrg;
	unsigned int            m_KillCount;///����ɱ���˶��ٵ���
	unsigned int            m_LostCount;///�ж���������


	///�����б�,��14�ֶ���
	EnemyFormatCollect      m_EnemyFormatCollect;
	bool                    m_needCreate;


	


};