
#pragma once


#include "GameState.h"



class GSSelectMode :public GameState
{
public:

	GSSelectMode();

	~GSSelectMode();



		 
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


     ///����ui
	void initUI();

	///����ui
	void DestroyUI();


protected:

	UIBase* m_pUI;


};