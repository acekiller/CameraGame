/***********************************
����״̬
****************************************/


#ifndef  GS_Test_h_h
#define  GS_Test_h_h


#include "GameState.h"
#include "enemy.h"
#include "WarManager.h"



class GSTest :public GameState
{
public:

	GSTest();

	~GSTest();


		 
    /**
     *״̬��ʼ����,
     */
	virtual void  begin( );
    
	/**
     *״̬��������
     */
	virtual void  end( );
    
    
	/**���º���*/
	virtual StateType update(float time);




protected:

	
	EnemyCollect m_EnemyCollect;




};



#endif