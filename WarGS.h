//
//  WarGS.h
//  ogreApp
//
//  Created by thcz on 11-6-22.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//


#pragma once


#include "GameState.h"
//#include "Bullet.h"


class WarManager;
class GameMode;
typedef std::vector<GameMode*>GameModeCollect;
class WarGS :public GameState
{
    
public:
    WarGS();
    
    ~WarGS();
    
    
protected:
    
    void begin();
    
    void end();
    
    virtual StateType update(float time);
    
   
    
    
    /**�����س������ݣ���������ͷ�˶�*/
    void updateAccelerometer();

    
protected:
    


	void beginTouch(int x,int y);
    
    ///��ʼ����Ƶ��ͼ
    void initVideoTeture();
    
  
    
    
    WarManager* m_pWarManager;
    
    Ogre::SceneNode* m_pCameraNode;


	GameModeCollect m_GameModeCollect;
	GameMode*       m_ActiveGameMode;
	
    
    
    
};