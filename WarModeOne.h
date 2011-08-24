/**********************************************
ս��ģʽ1
*****************************************************/

#include "WarMode.h"

class GameState;
class WarManager;
class UIWarone;

class WarModeOne :public WarMode, public WarListener
{

public:

	WarModeOne(GameState* pGameState);

	~WarModeOne();


	/**��ʼս��*/
	virtual void start();

	/**ս������*/
	virtual	void end();

	/**ÿ֡����*/
	virtual void update(float time);



protected:


	virtual void updateAccelerometer();

	///��ʼ�����е�����
	void  initEnemyFormat();

	/**��ʼ��ui*/
	void  initUI();

	/**����ui*/
	void  destroyUI();

	/**����һ������*/
	void _createEnemyQueue();

	/**��������¼�*/
	virtual  void beginTouch(int x,int y);




	///�ص�����
	///ɱ��һ�ӵ���
	virtual void onKillEnemyQueue(EnemyQueue* pEnemyQueue);

	///��������
	virtual void onLostEnemyQueue(EnemyQueue* pEnemyQueue);

	virtual void onCrateEnemyQueue(EnemyQueue* pEnemyQueue){}


protected:


	WarManager*    m_pWarManager;//

	Ogre::SceneManager*   m_pSceneMrg;
           
	EnemyFormatCollect   m_EnemyFormatCollect;


	float                m_GameLeft;///��Ϸ����
	float                m_CurrentTime; ///��Ϸ��ǰʱ��

	bool                 m_needCreate;///�Ƿ���Ҫ����һ������
	unsigned int         m_CreateIndex; ///��ǰ�����ĵڼ�������;
	UIWarone*            m_pUI;
	UIBase*              m_pUIBalance;

	float                m_Minx;        ///��Сx����Ƕ�
	float                m_Maxx;
	float                m_Miny;
	float                m_Maxy;
	float                m_Minz;
	float                m_Maxz;      

	unsigned int            m_KillCount;///����ɱ���˶��ٵ���
	unsigned int            m_LostCount;///�ж���������
	float                m_EnemyLeftTime; ///������������
	
	

};
