#include "pch.h"
#include "UISelectMode.h"
#include "Widget.h"
#include "Config.h"
#include "Application.h"
#include "Config.h"


UISelectMode::UISelectMode()
:UIBase("UISelectMode","")
{



}



UISelectMode::~UISelectMode()
{


}



/**��ʼ��*/
void UISelectMode::init()
{
	UIBase::init();

	///ģʽѡ�񱳾�ͼ
	StaticImage* pImage=new StaticImage("SelectModeBackGround","jieshu_background.png");
	registerWidget(pImage);
	pImage->setMetricsMode(Ogre::GMM_RELATIVE);
	pImage->setHorizontalAlignment(Ogre::GHA_LEFT);
	pImage->setVerticalAlignment(Ogre::GVA_TOP);
	pImage->setWidth(1.0f);
	pImage->setHeight(1.0f);


	///��̬ͼƬstage
    pImage=new StaticImage("SelectMode_StageImage","moshi_stage.png");
	registerWidget(pImage);
	pImage->setVerticalAlignment(Ogre::GVA_TOP);
	pImage->setTop(100);
	int width=256;
	int height=128;
	pImage->setWidth(width);
	pImage->setLeft(width*-0.5f);



	


	///ģʽ1��ť
	ImageButton* pPlayButton=new ImageButton("SelectMode_1","moshi_leftright.png","moshi_leftright.png");
	registerWidget(pPlayButton);
	pPlayButton->setHorizontalAlignment(Ogre::GHA_LEFT);
	width=pPlayButton->getWidth();
	height=pPlayButton->getHeight();
	pPlayButton->setLeft(100);
	pPlayButton->setTop(height*(-0.5f));



	///ģʽ2��ť
	pPlayButton=new ImageButton("SelectMode_2","moshi_updown.png","moshi_updown.png");
	registerWidget(pPlayButton);
	pPlayButton->setHorizontalAlignment(Ogre::GHA_CENTER);
	width=pPlayButton->getWidth();
	height=pPlayButton->getHeight();
	pPlayButton->setLeft(width*(-0.5f));
	pPlayButton->setTop(height*(-0.5f));




	///ģʽ3��ť
	pPlayButton=new ImageButton("SelectMode_3","moshi_smile.png","moshi_smile.png");
	registerWidget(pPlayButton);
	pPlayButton->setHorizontalAlignment(Ogre::GHA_RIGHT);
	width=pPlayButton->getWidth();
	height=pPlayButton->getHeight();
	pPlayButton->setLeft(-width-100.0f);
	pPlayButton->setTop(height*(-0.5f));
	





	///���ذ�ť
	Widget* pReturnButton=new ImageButton("SelectMode_return","moshi_fanhui_press.png","moshi_fanhui_release.png");
	pReturnButton->setHorizontalAlignment(Ogre::GHA_LEFT);
	pReturnButton->setWidth(80);
	pReturnButton->setHeight(80);
	pReturnButton->setLeft(10);
	pReturnButton->setVerticalAlignment(Ogre::GVA_BOTTOM);
	pReturnButton->setTop(-128);
	registerWidget(pReturnButton);






	return ;
}

void UISelectMode::buttonHit(Widget* button)
{
	const  Ogre::String&  name=button->getName();

	///����Ƿ��ذ�ť
	if(name=="SelectMode_return")
	{
		Application::getSingleton().getCurrentActive()->setNextStateType(ST_GAMEPLAY);
		return ;

	}


	if(name=="SelectMode_1")
	{
     g_userInformation.setWarMode(0);

	}else if(name=="SelectMode_2")
	{
        g_userInformation.setWarMode(1);
	}else if(name=="SelectMode_3")
	{

    g_userInformation.setWarMode(2);
	}



	Application::getSingleton().getCurrentActive()->setNextStateType(ST_CAPTUREFACE);

	return ;


}