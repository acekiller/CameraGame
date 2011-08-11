/*************************************
��Ϸս��ģʽ3
***************************************/


#pragma  once 

#include "WarMode.h"
#include  "WarItem.h"


class GameState;
class UIWarModeThree;
class WarItemManager;
class WarItem;

class Item;


class WarModeThree :public WarMode,public WarItemListen
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
	virtual void onHitTarget(WarItem* pItem,Enemy* pEnemy);


	/**����������*/
	void addPower(float power){m_CurrentPower+=power;}

	/**��ȡ��ǰ������*/
	float getCurrentPower()const {return m_CurrentPower;}

    /**��ȡ�����۵Ĵ�С*/
	float getMaxPower()const     {return m_MaxPower;}

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
	float           m_LastFireTime; ///��һ�ι�����ʱ��


	Enemy*          m_pTargetEnemy;
	WarItemManager* m_pWarItemManager;

	Ogre::StringVector m_AnimationCollect; ///�����к�Ķ����б�


};