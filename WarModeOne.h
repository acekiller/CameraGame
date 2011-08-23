/**********************************************
ս��ģʽ1
*****************************************************/

#include "WarMode.h"

class GameState;
class WarManager;


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


	WarManager*    m_pWarItemManager;//

	Ogre::SceneManager*   m_pSceneMrg;
           
	EnemyFormatCollect   m_EnemyFormatCollect;


	float                m_GameLeft;///��Ϸ����
	float                m_CurrentTime; ///��Ϸ��ǰʱ��

	bool                 m_needCreate;///�Ƿ���Ҫ����һ������
	unsigned int         m_CreateIndex; ///��ǰ�����ĵڼ�������;

	UIBase*              m_pUI;

	

};
