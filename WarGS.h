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
class WarMode;
typedef std::vector<WarMode*>WarModeCollect;
class WarGS :public GameState
{
    
public:
    WarGS();
    
    ~WarGS();
    
    
protected:
    

    void begin();
    
    void end();
    
    virtual StateType update(float time);
    
    /**�������������ݣ���������ͷ�˶�*/
    void updateAccelerometer();

    
protected:


	///��ʼ��ui
	void intiUI();

	///����ui
	void destroyUI();
   

	void beginTouch(int x,int y);
    
    ///��ʼ����Ƶ��ͼ
    void initVideoTeture();


	/**��ʼ�����е�ս��ģʽ*/
	void initWarMode();

	/**�������е�ս��ģʽ*/
	void destroyWarMode();
    
    /**��ʼ��Ӱ��*/
    void initBackGround();
    
    /**���ٱ�����*/
    void destroyBackGround();
    
    
    
protected:
    
    
  
    
    
    WarManager* m_pWarManager;
    
    Ogre::SceneNode* m_pCameraNode;


//	WarModeCollect m_WarModeCollect;
	WarMode*       m_ActiveWarMode;
	

	UIBase*        m_pUIPause;
    
    
    
    ///��Ӱ��
    Ogre::Entity*      m_BackGround;
    
    Ogre::TexturePtr   m_pVideoTexture;

};