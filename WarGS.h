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


class BulletManager;

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
    
  
    
    
    BulletManager* m_pBulletManager;
    
    Ogre::SceneNode* m_pCameraNode;

    
    
    
};