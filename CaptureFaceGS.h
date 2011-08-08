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
#include  "ogreapp/ofxiPhoneVideoGrabber.h"






class UISelectUser;
class UICaptureFace;
class UIBase;
class CaptureFaceGS : public GameState
{

    
public:
    
    CaptureFaceGS();
    
    
    ~CaptureFaceGS();
    
    
    
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
	
    
    
	virtual void  beginTouch(int x,int y);
	    
	
    
    
protected:
    
   


    /**��ʼ������ͷ*/
   // void initVideo();

    /**��������ͷ*/
    //void updateVideo();
    
    

	
    


protected:


	///ui��غ���
	void initUI();


	void destroyUI();


protected:
    
    
    
    Ogre::SceneNode*   m_pCameraNode;
    
       

    
    
    
#if defined  __arm__

    //ofxiPhoneVideoGrabber* m_pVideo;
#endif
    
    
    UICaptureFace*         m_pCaptureUI;///������

	UISelectUser*         m_pSelectUserUI;///ѡ���û�

	UIBase*               m_pSelectHeadUI;///ѡ��ͷ��

	UIBase*               m_pSelectFaceUI;//ѡ������
    
    
};
