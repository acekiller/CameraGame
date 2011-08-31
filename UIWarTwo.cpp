#include "pch.h"
#include "UIWarTwo.h"
#include "Widget.h"
#include "WarMode.h"
#include "WarManager.h"
#include "Application.h"
#include "EnemyQueue.h"
#include "UIWarPause.h"
#include "Tool.h"

//-----------------------------------------------------------------
UIWarModeTwo::UIWarModeTwo()
:UILayout("moshi2"),m_pRotateImage(NULL),m_pEnemy(NULL),m_PauseButton(NULL)
{

	memset(m_ScoreImage,0,5);

}


//-----------------------------------------------------------------
UIWarModeTwo::~UIWarModeTwo()
{


}


//-----------------------------------------------------------------


void  UIWarModeTwo::update(float time)
 {

	 UILayout::update(time);

	 updateEnemyDir();
 }


//-----------------------------------------------------------------
void UIWarModeTwo::init()
{
	UILayout::init();


	///ָʾ�����е��˳��ֵ���ת��ť
	m_pRotateImage=new RotateImage("WarModeTwo_Enemey_Dir","youxi_fangxiang.png");
	//m_pRotateImage->setWidth(40);
	registerWidget(m_pRotateImage);


	m_PauseButton=static_cast<ImageButton*>(getWidgetByName("moshi2/moshi2zantingjian"));
	Widget* pWidget=getWidgetByName("moshi2/moshi2shengming1");
    assert(pWidget);
	m_LifeCollect.push_back(pWidget);

	pWidget=getWidgetByName("moshi2/moshi2shengming2");
	assert(pWidget);
	m_LifeCollect.push_back(pWidget);

	pWidget=getWidgetByName("moshi2/moshi2shengming3");
	assert(pWidget);
	m_LifeCollect.push_back(pWidget);


	m_ScoreImage[0]=static_cast<StaticImage*>(getWidgetByName("moshi2/moshi2xiaoshuzi00"));
	m_ScoreImage[1]=static_cast<StaticImage*>(getWidgetByName("moshi2/mosho2xiaoshuzi0"));
	m_ScoreImage[2]=static_cast<StaticImage*>(getWidgetByName("moshi2/mosho2xiaoshuzi8"));
	m_ScoreImage[3]=static_cast<StaticImage*>(getWidgetByName("moshi2/moshi2xiaoshuzi5"));
	m_ScoreImage[4]=static_cast<StaticImage*>(getWidgetByName("moshi2/moshi2xiaoshuzi9"));


	/*

	///��ͣ��ť
	m_PauseButton=new ImageButton("WarModeTwo_PauseButton","youxi_zhanting_release.png","youxi_zhanting_press.png");
	registerWidget(m_PauseButton);
	m_PauseButton->setHorizontalAlignment(Ogre::GHA_LEFT);
	m_PauseButton->setVerticalAlignment(Ogre::GVA_TOP);
	m_PauseButton->setLeft(32);
	m_PauseButton->setTop(32);
	m_PauseButton->setWidth(80);
	m_PauseButton->setHeight(80);

	
	///��ǹ��ť
    m_pFireButton =new ImageButton("WarModeTwo_FirButton","youxi_gongji_release.png","youxi_gongji_press.png");
	registerWidget(m_pFireButton);
	m_pFireButton->setHorizontalAlignment(Ogre::GHA_RIGHT);
	m_pFireButton->setVerticalAlignment(Ogre::GVA_BOTTOM);
	m_pFireButton->setLeft(-m_pFireButton->getWidth());
	m_pFireButton->setTop(-m_pFireButton->getHeight());


	///׼��
	m_FirePoint=new StaticImage("WarModeTwo_FirePoint","youxi_zhunxin.png");
	registerWidget(m_FirePoint);
	m_FirePoint->setLeft(m_FirePoint->getWidth()*(-0.5f));
	m_FirePoint->setTop(m_FirePoint->getHeight()*(-0.5f));


	///��ʼ������������ʾ
	int startleft=-64*3;
	for(int i=0;i<3;++i)
	{
		StaticImage* pImage=new StaticImage("WarModeTwo_Lift_"+Ogre::StringConverter::toString(i),"youxi_shengmingzhi.png");
		registerWidget(pImage);
		pImage->setHorizontalAlignment(Ogre::GHA_RIGHT);
		pImage->setVerticalAlignment(Ogre::GVA_TOP);

		pImage->setWidth(50);
		pImage->setHeight(40);
		pImage->setLeft(startleft+(i)*64);
		pImage->setTop(40);
		m_LifeCollect.push_back(pImage);

	}


	*/
	


}



//-----------------------------------------------------
void UIWarModeTwo::updateEnemyDir()
{

	///������������Ͳ�����
	if(WarManager::getSingleton().isGameEnd())
	{
	    m_pRotateImage->hide();
		return ;
	}


	if(m_pEnemy==NULL)
	{
		m_pRotateImage->hide();
		return ;
	}

	///������������Ļ�ϳ����˾����ؼ�ͷ
	Ogre::Camera* pCamera=Application::getSingleton().getMainCamera();

	const Ogre::Matrix4& viewMat=pCamera->getViewMatrix();
	Ogre::Vector3 pos=m_pEnemy->getSceneNode()->getPosition();
	pos=viewMat*pos;

	Ogre::AxisAlignedBox box=m_pEnemy->getWordBox();

	if(pCamera->isVisible(box))
	{
		m_pRotateImage->hide();

		//m_pRotateImage->show();
		return ;
	}else
	{
		m_pRotateImage->show();
	}



	float  ang= (Ogre::Math::ATan(pos.y/pos.x)).valueDegrees();

	///��������
	if(pos.x<0&&pos.y>0)
	{

		ang=90.0f+(90+ang);

	}else if(pos.x<0&&pos.y<0)//��������
	{

		ang=180.0f+ang;
	}
	Ogre::Radian Radian=Ogre::Degree(ang);

	m_pRotateImage->setOrientation(Radian.valueRadians());
	float y=Ogre::Math::Sin(Radian);
	float x=Ogre::Math::Cos(Radian);

	float dis=220;
	m_pRotateImage->setLeft(x*dis);
	m_pRotateImage->setTop(-y*dis);

	
}

//----------------------------------------------------------------
void  UIWarModeTwo::buttonHit(Widget* button)
{
	
	if(button==m_PauseButton)///�������ͣ
	{

		UIWarPause* pPauseUI= static_cast<UIWarPause*>(Application::getSingleton().getUIByName("zantingjiemian"));
		
		std::vector<UIBase*>showList;
		showList.push_back(this);
		pPauseUI->setEndShowUI(showList);

		pPauseUI->setVisible(true);
		setVisible(false);


	}
}


//-------------------------------------------------------------------
 void UIWarModeTwo::onBeginTouch(int x,int y)
 {
	 UILayout::onBeginTouch(x,y);

	 ///������������ͣ��ť�ͺ���
	 if(m_PauseButton->isCursorOver(m_PauseButton->getOverlayElement(),Ogre::Vector2(x,y),4))
	 {
		 return ;
	 }
	 WarManager::getSingleton().fire();
	 return ;
 }



//----------------------------------------------------------------
void  UIWarModeTwo::onKillEnemyQueue(EnemyQueue* pEnemyQueue)
{

	m_pEnemy=NULL;
	return ;
}

//----------------------------------------------------------------
void  UIWarModeTwo::onLostEnemyQueue(EnemyQueue* pEnemyQueue)
{
	///������ʾһ������ͼ��

	WidgetCollect::iterator it=	m_LifeCollect.begin();
	WidgetCollect::iterator itend=	m_LifeCollect.end();

	for(;it!=itend;++it)
	{
		if(	(*it)->isVisible())
		{
			(*it)->hide();
			return ;
		}
	}

	m_pEnemy=NULL;



	return ;
}

//----------------------------------------------------------------
void UIWarModeTwo::onCrateEnemyQueue(EnemyQueue* pEnemyQueue)
{
	m_pEnemy=pEnemyQueue;
}


///-------------------------------------------------------------
void UIWarModeTwo::reset()
{

	WidgetCollect::iterator it=	m_LifeCollect.begin();
	WidgetCollect::iterator itend=	m_LifeCollect.end();

	for(;it!=itend;++it)
	{
		(*it)->show();
	}

	m_pEnemy=NULL;

	////��������
	Ogre::String textureName="set:jifengqiepian0_21 image:gongyongxiaoziti_0";
	for(int i=0;i<5;++i)
	{
		m_ScoreImage[i]->setImage(textureName,true);
	}

}


void UIWarModeTwo::setScore(unsigned int score)
{

	Ogre::String textureName="set:jifengqiepian0_21 image:gongyongxiaoziti_";
	int temValue=Tools::getValueByBit(score,1);
	m_ScoreImage[0]->setImage(textureName+Ogre::StringConverter::toString(temValue),true);

	temValue=Tools::getValueByBit(score,2);
	m_ScoreImage[1]->setImage(textureName+Ogre::StringConverter::toString(temValue),true);

	temValue=Tools::getValueByBit(score,3);
	m_ScoreImage[2]->setImage(textureName+Ogre::StringConverter::toString(temValue),true);

	temValue=Tools::getValueByBit(score,4);
	m_ScoreImage[3]->setImage(textureName+Ogre::StringConverter::toString(temValue),true);

	temValue=Tools::getValueByBit(score,5);
	m_ScoreImage[4]->setImage(textureName+Ogre::StringConverter::toString(temValue),true);
	return ;
}