#include "pch.h"
#include "GameState.h"
#include "Application.h"



GameState::GameState(StateType stateType)
:State(stateType),m_pSceneManager(NULL)
{
    
    m_pSceneManager=Application::getSingleton().getMainSceneManager();
    
}


GameState::~GameState()
{
    
}


/*״̬��ʼ����,
 */
void  GameState::begin( )
{
	State::begin();
    
}

/*
 *״̬��������
 */
void  GameState::end( )
{
    State::end();
      
}



StateType GameState::update(float time)
{
    
  return  State::update(time);
    
}



