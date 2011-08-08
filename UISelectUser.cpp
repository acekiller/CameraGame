#include "pch.h"
#include "UISelectUser.h"
#include  "Widget.h"
#include "Application.h"
#include "Config.h"
#include "Tool.h"





UISelectUser::UISelectUser()
:UIBase("UISelectUser",""),m_ToCaptureButton(NULL),m_pReturnButton(NULL),m_NeedUpdate(false)
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


	///����
	StaticImage* pImage=new StaticImage("SelectUserBackGround","tuku_background.png");
	registerWidget(pImage);
	Ogre::OverlayElement* pElment=pImage->getOverlayElement();
	pElment->setMetricsMode(Ogre::GMM_RELATIVE);
	pElment->setHorizontalAlignment(Ogre::GHA_LEFT);
	pElment->setVerticalAlignment(Ogre::GVA_TOP);
	pElment->setWidth(1.0f);
	pElment->setHeight(1.0f);




	///�������ս���
	m_ToCaptureButton=new ImageButton("UISelectUser_GoCapture","tuku_zuoanniu_release.png","tuku_zuoanniu_press.png");
	registerWidget(m_ToCaptureButton);
	m_ToCaptureButton->_assignListener(this);
	pElment=m_ToCaptureButton->getOverlayElement();
	pElment->setHorizontalAlignment(Ogre::GHA_LEFT);
	m_ToCaptureButton->setWidth(80);
	m_ToCaptureButton->setHeight(80);
	


	///���ذ�ť

	///������һ�㰴ť
	m_pReturnButton=new ImageButton("UISelctReturnButton,","moshi_fanhui_release.png","moshi_fanhui_press.png");
	registerWidget(m_pReturnButton);
	m_pReturnButton->setHorizontalAlignment(Ogre::GHA_LEFT);
	m_pReturnButton->setLeft(10);
	m_pReturnButton->setVerticalAlignment(Ogre::GVA_BOTTOM);
	m_pReturnButton->setTop(-128);
	m_pReturnButton->setWidth(80);
	m_pReturnButton->setHeight(80);





	///ɾ����ʾ��
   StaticImage* pDeleteImage=new StaticImage("UISelectDeleteImage","tuku_delete_0.png");
   registerWidget(pDeleteImage);
   pDeleteImage->setVerticalAlignment(Ogre::GVA_BOTTOM);
   pDeleteImage->setWidth(256);
   pDeleteImage->setTop(-pDeleteImage->getHeight()-20);
   pDeleteImage->setLeft(-pDeleteImage->getWidth()*0.5f);



	return ;
}



//-----------------------------------------------
void UISelectUser::update(float time)
{
	UIBase::update(time);

	if(m_NeedUpdate)
	{
		updateUserList();
	}

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

	if(pUserList.isNull())
		return ;

	///���������е�
	destroyAllUserList();

	m_UserList=pUserList;

	///���ֻ��ʾ5��
    int userSize=m_UserList->size();
	if(userSize>5)
	{
		userSize=5;
	}

	for(int i=0;i<userSize;++i)
	{
		//Ogre::String buttonName="UserFace_"+Ogre::StringConverter::toString(i);
		Ogre::String imageName=m_UserList->at(i);
		TimeImageButton* pButton=new TimeImageButton(imageName, imageName);
		registerWidget(pButton);
		m_UserButtonCollect.push_back(pButton);
		pButton->setHorizontalAlignment(Ogre::GHA_LEFT);
		pButton->setTop(pButton->getHeight()*-0.5f);
		int width= pButton->getWidth();
		width+=20;//���¿�϶
		pButton->setLeft(200+width*i);

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
void UISelectUser::onEndTouch(int x,int y)
{
	UIBase::onEndTouch(x,y);

	///���һ���û���ť��û�е㵽������ɾ��״̬
	bool needRest=true;

	ImageButtonCollect::iterator it=m_UserButtonCollect.begin();
	ImageButtonCollect::iterator itend=m_UserButtonCollect.end();
	Ogre::Vector2  area(x,y);

	for(;it!=itend;++it)
	{
		if((*it)->isCursorOver((*it)->getOverlayElement(),area))
		{

			needRest=false;
			break;;
		}
	}

	if(needRest)
	{
		resetUserFaceButton();
	}


}

//----------------------------------------------------------
void   UISelectUser::resetUserFaceButton()
{
	ImageButtonCollect::iterator it=m_UserButtonCollect.begin();
	ImageButtonCollect::iterator itend=m_UserButtonCollect.end();

	for(;it!=itend;++it)
	{
		(*it)->reset();
	}
	return ;
}


//----------------------------------------------------------
void  UISelectUser::setVisible(bool b)
{
    UIBase::setVisible(b);
    if(b)
    {
        m_NeedUpdate=true;
    }
    
}


//-------------------------------------------------------
void UISelectUser::buttonHit(Widget* pbutton)
{
	if(pbutton==NULL)
		return ;


	//������������հ�ť
	if(pbutton==m_ToCaptureButton)
	{
		setVisible(false);

		UIBase* pCaptureFace= Application::getSingleton().getUIByName("CaptureFaceUI");
		assert(pCaptureFace);
		pCaptureFace->setVisible(true);
		return ;

	}else if(pbutton==m_pReturnButton)//����Ƿ��ذ�ť
	{
		Application::getSingleton().getCurrentActive()->setNextStateType(ST_SELECTMODE);
		return ;

	}



	///�����ѡ�����е���
	const Ogre::String& imageName=pbutton->getName();
	size_t size=m_UserList->size();
	for(size_t i=0;i<size;++i)
	{
		Ogre::String username=m_UserList->at(i);

		if(username==imageName)
		{

			TimeImageButton*  pTimeButton=static_cast<TimeImageButton*>(pbutton);

			///�����ɾ���û���
			if(pTimeButton->getState()==TimeImageButton::Press)
			{

				username=Tools::getUserFacePath()+"/"+username;
				::remove(username.c_str());
				m_NeedUpdate=true;
				return ;
			}else if(pTimeButton->getState()==TimeImageButton::NORMAL)///�?????头�????
			{
				setVisible(false);
				g_userInformation.setUserImage(username);
				UIBase* pSelectFaceMode= Application::getSingleton().getUIByName("UISelectHead");
				pSelectFaceMode->setVisible(true);

			}


		}


	}



	return ;
}
