/*************************************
��Ϸս��ģʽ3
***************************************/


#pragma  once 

#include "WarMode.h"


class GameState;
class UIWarModeThree;
class WarItemManager;
class WarItem;

class Item;


class WarModeThree :public WarMode
{

public:

	/**���캯��*/
	WarModeThree( GameState* pGameState);


	~WarModeThree();


	/**��ʼս��*/
	virtual void start();

	/**ս������*/
	virtual	void end();

	/**ÿ֡����*/
	virtual void update(float time);


	/**��������¼�*/
	virtual  void beginTouch(int x,int y);


	/**Ŀ�����˱����߻��к�Ļص�*/
	void   notityEmemyHit(Enemy* pEnemy,WarItem* pWarItem);


protected:


	void initUI();

	void destroyUI();


	/**����������ʾ
	*/
	void updatePower(float time);



protected:

	

	UIWarModeThree* m_pUIWar;

	float           m_CurrentPower;///��ǰ������
	float           m_MaxPower;    ///������
	float           m_StopFireTime; ///ֹͣ������ʱ�� 


	Enemy*          m_pTargetEnemy;

	WarItemManager* m_pWarItemManager;


};