
/****************************************************
��ʼ��Ϸ״̬��play����


********************************************************/






#pragma  once


#include "GameState.h"
#include "UIManager.h"


class GSGamePlay :public GameState
{

public:

	GSGamePlay();


	~GSGamePlay();


	 
    /*
     *״̬��ʼ����,
     */
	virtual void  begin( );
    
	/*
     *״̬��������
     */
	virtual void  end( );
    
    
	/**���º���*/
	virtual StateType update(float time);




protected:


	/**��ʼ�����ui*/
	void initUI();

	/**�������ui*/
	void destroyUI();


protected:


	UICollect m_UICollect;



};



