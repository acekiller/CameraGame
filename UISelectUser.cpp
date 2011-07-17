
#include "pch.h"
#include "UISelectUser.h"
#include  "Widget.h"
#include "Application.h"
#include "Config.h"
#include "Tool.h"





UISelectUser::UISelectUser()
:UIBase("UISelectUser",""),m_ToCaptureButton(NULL),m_NeedUpdate(false)
{


}


//----------------------------------------
UISelectUser::~UISelectUser()
{


}

//-----------------------------------------------
void  UISelectUser::init()
{

	UIBase::init();


	StaticImage* pImage=new StaticImage("SelectUserBackGround","sdk_button_up.png");
	registerWidget(pImage);
	Ogre::OverlayElement* pElment=pImage->getOverlayElement();
	pElment->setMetricsMode(Ogre::GMM_RELATIVE);
	pElment->setHorizontalAlignment(Ogre::GHA_LEFT);
	pElment->setVerticalAlignment(Ogre::GVA_TOP);
	pElment->setWidth(1.0f);
	pElment->setHeight(1.0f);
    
    
    
    
    ///创建左边按钮用来跳到捕获脸的界面。
   m_ToCaptureButton=new ImageButton("UISelectUser_GoCapture","sdk_button_up.png","sdk_button_down.png");
    registerWidget(m_ToCaptureButton);
    m_ToCaptureButton->_assignListener(this);
    pElment=m_ToCaptureButton->getOverlayElement();
	pElment->setHorizontalAlignment(Ogre::GHA_LEFT);
	//pElment->setWidth(1.0f);
	//pElment->setHeight(1.0f);


    
    
    

    
    
    ///创建五个按钮用来选择已拍照的人物。
    
    //ImageButton* pButton =new ImageButton("SelectUser_1",















	return ;
}



///每帧更新
void UISelectUser::update(float time)
{
	UIBase::update(time);

	if(m_NeedUpdate)
	{
		updateUserList();
	}
    
    
    
    /*
    Ogre::RenderWindow* pWind=Application::getSingleton().getRenderWindow();
    int ViewportCount=pWind->getNumViewports();
    
    int winWidth= pWind->getWidth();
    int winHeight= pWind->getHeight();
    
    
    for(int i=0;i<ViewportCount;++i)
    {
        Ogre::Viewport* pViewport=pWind->getViewport(0);
        pViewport->setBackgroundColour(Ogre::ColourValue(1.0f,0,0));
        
        float left=pViewport->getLeft();
        float top=pViewport->getTop();
        
        float width=pViewport->getWidth();
        float height=pViewport->getHeight();
        
        
        left+=height;
        
        
    }
    
    Ogre::RenderSystem::RenderTargetIterator targetIt=Ogre::Root::getSingleton().getRenderSystem()->getRenderTargetIterator();    
    
    while (targetIt.hasMoreElements())
    {
        Ogre::RenderTarget *pTarget=targetIt.getNext();
        ViewportCount=pTarget->getNumViewports();
    }
    
    //*/
    
    
    
    
	return ;

}


//-------------------------------------------------------
void  UISelectUser::updateUserList()
{

	Ogre::StringVectorPtr pUserList=Tools::getUserFaceFileList();
	setUserList(pUserList);
	m_NeedUpdate=false;

}



//-------------------------------------------------------
void  UISelectUser::setUserList(Ogre::StringVectorPtr pUserList)
{

	///如果传无效指针忽视
	if(pUserList.isNull())
		return ;

	///删除旧的
	destroyAllUserList();

	m_UserList=pUserList;

	///循环创建有用户按钮,最多只创建5个
	int userSize=m_UserList->size();
	if(userSize>5)
	{
		userSize=5;
	}

	for(int i=0;i<userSize;++i)
	{
		//Ogre::String buttonName="UserFace_"+Ogre::StringConverter::toString(i);
		Ogre::String imageName=m_UserList->at(i);
		ImageButton* pButton=new ImageButton(imageName, imageName,imageName);
		registerWidget(pButton);
		m_UserButtonCollect.push_back(pButton);

		Ogre::OverlayElement* pElement=pButton->getOverlayElement();
		pElement->setHorizontalAlignment(Ogre::GHA_LEFT);
		pElement->setLeft(200+150*i);

	}




	return ;

}


//-------------------------------------------------------
void  UISelectUser::destroyAllUserList()
{

	ImageButtonCollect::iterator it=m_UserButtonCollect.begin();
	ImageButtonCollect::iterator itend=m_UserButtonCollect.end();

	for(;it!=itend;++it)
	{
		destroyWidget(*it);
	}

	m_UserButtonCollect.clear();
	
	return ;

}

//-------------------------------------------------------
void UISelectUser::buttonHit(Widget* pbutton)
{
	if(pbutton==NULL)
		return ;


	///如果是跳到捕脸界面
	if(pbutton==m_ToCaptureButton)
	{
		setVisible(false);
		
		UIBase* pCaptureFace= Application::getSingleton().getUIByName("CaptureFaceUI");
		assert(pCaptureFace);
		pCaptureFace->setVisible(true);

	}

	

	////不能在些删除控件。

	///如果点击的人物脸就删除这个用户
    if(m_UserList.isNull()==false)
    {
	const Ogre::String& imageName=pbutton->getName();
    size_t size=m_UserList->size();
	for(size_t i=0;i<size;++i)
	{
		Ogre::String username=m_UserList->at(i);

		if(username==imageName)
		{

				//pArchive->remove(username);
				username=g_UserFacePath+"/"+username;
				::remove(username.c_str());
                m_NeedUpdate=true;
				return ;
		}

	}
    }



//	Ogre::StringVectorPtr pFileList=Tools::getUserFaceFileList();
//	this->setUserList(pFileList);

	

	return ;


}



