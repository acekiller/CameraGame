#pragma once


#include "state.h"
#include  "UIBase.h"


class GameState : public State
{
public:
    
	GameState( StateType stateType );
    
    
	virtual ~GameState();
    
	
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
	
    
    
	virtual void  beginTouch(int x,int y)
	{ 
		return ; 
	}
    
	virtual void  endTouch(int x,int y)
	{
		return ; 
	}
	virtual void  moveTouch(int x,int y)
	{ 
		return ; 
	}

	    
    
protected:
    
    
    
    Ogre::SceneManager* m_pSceneManager;
	

  
    
};

