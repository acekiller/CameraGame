//
//  CaptureVideoGS.h
//  ogreApp
//
//  Created by thcz on 11-6-22.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//

#pragma once


#include "GameState.h"
#include  "state.h"
#include  "ofxiPhoneVideoGrabber.h"








class CaptureFaceGS : public GameState
{

    
public:
    
    CaptureFaceGS();
    
    
    ~CaptureFaceGS();
    
    
    
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
	
    
    
	virtual void  beginTouch();
	    
	
    
    
protected:
    
    /**��ʼ��Ӱ��*/
    void initBackGround();


    /**��ʼ������ͷ*/
    void initVideo();

    /**��������ͷ*/
    void updateVideo();
    
    
    
    

protected:
    
    ///��Ӱ��
    Ogre::Entity*      m_BackGround;
    
    Ogre::SceneNode*   m_pCameraNode;
    
    Ogre::TexturePtr   m_pVideoTexture;
    
    
    
#if defined  __arm__

    //ofxiPhoneVideoGrabber* m_pVideo;
#endif
    
    
    UIBase*         m_pCaptureUI;
    
    
};
