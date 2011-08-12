//
//  inputListen.h
//  ogreApp
//
//  Created by thcz on 11-6-17.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//

#pragma once



#if OGRE_PLATFORM == OGRE_PLATFORM_IPHONE

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#include "../ofPoint.h"
#import  "Accelerometer.h"
class ofxAccelerometerHandler;

class InputListen :public Ogre::Singleton<InputListen>
{
public:
	 InputListen();

#else if OGRE_PLATFORM ==OGRE_PLATFORM_WIN32

#include "ois/ois.h"


#ifdef _DEBUG

#pragma comment(lib,"ois_d.lib")

#else
#pragma comment(lib,"ois.lib")

#endif

class InputListen :public Ogre::Singleton<InputListen>,public OIS::KeyListener, public OIS::MouseListener
{
public:

	 InputListen(HWND wnd);

#endif


    
public:
    
   
    
    ~InputListen();
    
    
    void  setupInput();
    
    
    /**��ʼ����������*/
    void beginGyroscope();
    
    /**��������������*/
	void endGyroscope();
    
    
    /**�ж��������Ƿ�����*/
    bool isGyroscopeActive()const{return m_IsDeviceActive;}
    
    
    /**��ʼ����*/
    void TouchBegan(int x,int y);

	/**��ָ�뿪*/
	void TouchEnd(int x, int y);

	/**��ָ����*/
	void TouchMove(int x, int y);

    
    /**��ȡ��������*/
    void Captuer();  
    



    
    const Ogre::Vector3&  getAccelerometerData()const ;
    
    const Ogre::Vector3&  getGyroscopeData()const;
    
    Ogre::Vector3  getSmoothAccelerometer();
    
    Ogre::Vector3  getSmoothGyroscope();


#if OGRE_PLATFORM ==OGRE_PLATFORM_WIN32


	/**OIS�ص�����*/
	bool mouseMoved(const OIS::MouseEvent &arg);

	bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	bool keyPressed(const OIS::KeyEvent &arg);

	bool keyReleased(const OIS::KeyEvent &arg);

#endif


    
protected:
    
    
    void  createInputDevices();
    
    /**�������е������豸*/
    void  destroyInputDevices();
    
    

    
    
    
    
    protected:
    
    
   
#if OGRE_PLATFORM ==OGRE_PLATFORM_IPHONE

    Accelerometer* m_pAccelerometer;
    ofxAccelerometerHandler*        m_AccelerHander; ///������
    ofxAccelerometerHandler*        m_GyroHander;    ///������

    
#else if OGRE_PLATFORM==OGRE_PLATFORM_WIN32



	HWND                    m_wnd;                      ///win32���ھ��
	OIS::InputManager*		mInputManager;				// ���������
	OIS::Mouse*				mMouse;						// ���
	OIS::Keyboard*			mKeyboard;					// ����


#endif
        
        bool       m_IsDeviceActive;///�ж��Ƿ��豸�Ƿ�����


		Ogre::Vector3  m_AccelerometerData;
		Ogre::Vector3  m_GyroscopeData;



};



