//
//  Application.h
//  ogreApp
//
//  Created by iMac on 11-6-15.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//
#pragma once

 

//#include "ogreConfig.h"
//#include "Ogreplatform.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_IPHONE

#include "FileSystemLayerImpl.h"
#include  "ogreapp/ofxiPhoneVideoGrabber.h"
#include "ogreapp/Accelerometer.h"
#include <sys/types.h>
#include <sys/stat.h>


#endif


#include "stateMachine.h"
#include "UIManager.h"
#include "UIImagesetManager.h"


class ofxiPhoneVideoGrabber;
class SdkTrayManager;
class InputListen;
class UIDebug;



class Application :public Ogre::Singleton<Application>, public StateMachine , public UIManager
{
    
public:
    
    Application();


    
    ~Application();
    
    
    /**��ʼ��
    */
    void init();
    
    /**������������
    */
    void destory();

	/**��ͣ������Ϸ
	*@remark ֻ����ͣ��Ϸ�߼���ui����Ⱦ������ͣ
	*/
	void pauseApp();

	/**������Ϸ*/
	void continueApp();
    
    
    /**��ʼ��ogre��Ⱦ��*/
    bool initOgreRender();

	/**�������е�ogre����*/
	void destroyOgreRender();
    
    /**��ʼ��ogre���������openles���������ʼ��*/
  //  bool initOgrePlugs();
   

    
    /**ÿ֡����
    @param time ��λΪ��
    */
    void update(float time);
    
    
    /**��ʼ����Ⱦ��Դ*/
    void initResource();

   
    
    /**��ʼ�������豸*/
    void initInputDevice();
    
    /***/
    void destroyInputDevice();
    
    /**���س����ĵ���������ڵ�*/
    Ogre::SceneNode* getMainCameraNode()const {return m_pCameraNode;}
    
    
    /**����������*/
    Ogre::Camera*   getMainCamera()const{return m_pCamera;}

    
    
    /**���س���������*/
    Ogre::SceneManager* getMainSceneManager()const {return m_pSceneManager;}
    


	//*/�����¼���

    /**��ʼ����*/
    void TouchBegan(int x,int y);
    
     /**��ָ�뿪*/
	void TouchEnd(int x,int y);

	/**��ָ����*/
	void TouchMove(int x,int y);

    
    /**��ʼ����ϷĿ¼*/
    void initGamePath();


	/**��ȡ��Ⱦ����*/
	Ogre::RenderWindow* getRenderWindows()const {return m_pRenderWindow;}


	//*/�����¼�����


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	///��ʼ֡ѭ��,windowsƽ̨��ʹ��
	void go();

	///window�º��������ں���
	bool  InitWindow(int width,int height);


    static	LRESULT MsgProc(HWND hWnd, DWORD message, WPARAM wParam, LPARAM lParam);

#else

	OgreBites::FileSystemLayerImpl* getFileSystem()const {return m_pFileSystem;}   
   
    
#endif

    
protected:
    
    /**��ʼ��������һ�������������ע�����е�״̬
     *�������������Ҫ�ֶ�ָ����ǰ�״̬��ͬʱ���û״̬��begin����
     */
	virtual void  initState();
    

    /**�����ֻ����ڵķ���ת��uiλ��*/
    void transformInputCoordinate(int&x, int &y);
    
    
    
    
    
protected:
    
   
    
    
protected:
    
    /**��ʼ������*/
    void initScene();
    
       
 
    
       
      
    Ogre::Root* m_pRoot;
    
  //  Ogre::StaticPluginLoader mStaticPluginLoader;
    
    Ogre::RenderWindow* m_pRenderWindow;
    
    Ogre::Viewport*     m_pViewPort;
    
    
    Ogre::SceneNode*     m_pCameraNode;
    Ogre::Camera*       m_pCamera;
    
    Ogre::SceneManager*    m_pSceneManager;
    

#if OGRE_PLATFORM == OGRE_PLATFORM_IPHONE

    OgreBites::FileSystemLayerImpl*    m_pFileSystem;



#else OGRE_PLATFORM ==OGRE_PLATFORM_WIN32

	HWND  mHwnd;
    HINSTANCE	mInstance;

#endif
    
    
    InputListen*            m_pInputListen;

	UIDebug*                  m_pDebugPanel;///debug���
 
	bool                     m_Pause;///�Ƿ���ͣ


	UIImagesetManager*       m_pImagesetMrg;
  
    
};



