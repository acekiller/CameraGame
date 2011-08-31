

#include "pch.h"
#include "UISelectHead.h"
#include "Widget.h"
#include "Application.h"
#include "Tool.h"
#include "Config.h"



FaceModeDataSource::FaceModeDataSource()
{

	m_ElementCollect.push_back(std::make_pair("InterfaceModel_duck.png","duck.mesh"));
	m_ElementCollect.push_back(std::make_pair("xuanmoxing_xuanzekuang_hema.png","hema.mesh"));
    m_ElementCollect.push_back(std::make_pair("xuanmoxing_xuanzekuang_laoshu.png","mouse.mesh"));
	m_ElementCollect.push_back(std::make_pair("InterfaceModel_xiaoji.png","xiaoji.mesh"));
	m_ElementCollect.push_back(std::make_pair("InterfaceModel_xiaolu.png","deer.mesh"));/*InterfaceModel_xiaoji*/
	m_ElementCollect.push_back(std::make_pair("InterfaceModel_xiaolu.png","head_tu.mesh"));
}

 
FaceModeDataSource::~FaceModeDataSource()
{


}
//---------------------------------------------------------------

unsigned int FaceModeDataSource::getElementCount()
{
	return m_ElementCollect.size();
}


	/**��ȡԪ�ص���ͼ��
*�ɹ�����true ʧ�ܷ���false
*/
bool  FaceModeDataSource::getElementTexture(unsigned int index,Ogre::String& textureName)
{
	if(index>=m_ElementCollect.size())
		return false;

	textureName=m_ElementCollect[index].first;//��ȡ��ͼ��
	return true;

}

	/**��ȡԪ�ص��û�����
	*�ɹ�����true ʧ�ܷ���false
	*/
bool FaceModeDataSource::getElementUserData(unsigned index,Ogre::String& elementData)
{

	if(index>=m_ElementCollect.size())
		return false;

	elementData=m_ElementCollect[index].second;//��ȡ�û�����
	return true;

}







//---------------------------------------------------------------
UISelectHead:: UISelectHead()
:UILayout("toutaoxuanzejiemian")
{


}


//---------------------------------------------------------------
 UISelectHead::~UISelectHead()
{


}


//---------------------------------------------------------------
 /*
void  UISelectHead::init()
{

	UIBase::init();

	//Ogre::SceneManager* pSceneMrg=Application::getSingleton().getMainSceneManager();
	//Ogre::Entity* pHead=pSceneMrg->createEntity("Head.mesh");
	//Ogre::SceneNode* pScenNode=  pSceneMrg->getRootSceneNode()->createChildSceneNode();
	//pScenNode->attachObject(pHead);


	StaticImage* pImage=new StaticImage("SelectHeadBackGround","jieshu_background.png");
	registerWidget(pImage);
	Ogre::OverlayElement* pElment=pImage->getOverlayElement();
	pImage->setMetricsMode(Ogre::GMM_RELATIVE);
	pImage->setHorizontalAlignment(Ogre::GHA_LEFT);
	pImage->setVerticalAlignment(Ogre::GVA_TOP);
	pImage->setLeft(0.0f);
	pImage->setWidth(1.0f);
	pImage->setTop(0.0f);
	pImage->setHeight(1.0f);

	SliderGallery* pSliderGallery=new SliderGallery("SelectHeadSliderGallery",new FaceModeDataSource(),"cz/SliderGallery");
	registerWidget(pSliderGallery);
	pSliderGallery->getOverlayElement()->setHorizontalAlignment(Ogre::GHA_LEFT);
	//pSliderGallery->getOverlayElement()->setLeft();




	m_pReturnButton=new ImageButton("SelectHeadReturn","moshi_fanhui_release.png","moshi_fanhui_press.png");
	m_pReturnButton->setHorizontalAlignment(Ogre::GHA_LEFT);
	m_pReturnButton->setLeft(10);
	m_pReturnButton->setVerticalAlignment(Ogre::GVA_BOTTOM);
	m_pReturnButton->setTop(-100);
	m_pReturnButton->setWidth(80);
	m_pReturnButton->setHeight(80);
	registerWidget(m_pReturnButton);





	//���ذ�ť



}


//----------------------------------------------------------------
void  UISelectHead::sliderGalleryhit(SrollButton* pbutton)
{

    const Ogre::String& userData=pbutton->getUserData();
	g_userInformation.setHeadMode(userData);

	///ѡ����ͷ�׽���ѡ�����ͽ���
	setVisible(false);
	UIBase* pSelectFace=Application::getSingleton().getUIByName("UISelectFaceMode");
	pSelectFace->setVisible(true);


	return ;

}

//*/
void UISelectHead::buttonHit(Widget* button)
{
	if(button==NULL)
		return ;

	const Ogre::String& widgetName=button->getName();

	///


	//���ذ�ť���ص�ѡ���������
	if(widgetName=="toutaoxuanze/toutaofanhui")
	{

		Ogre::StringVectorPtr pUserList=Tools::getUserFaceFileList();

		if(pUserList.isNull()||pUserList->empty())///���û����Ϣ�ͷ��ص���������
		{
		   
			UIBase* pUI=Application::getSingletonPtr()->getUIByName("zhaoxiang");
		    pUI->setVisible(true);
	
     	}else///���ص�ѡ���û��Ľ���
		{

			UIBase* pUI=Application::getSingletonPtr()->getUIByName("tukumoshi");
			pUI->setVisible(true);
		}
		setVisible(false);

		return ;

	}else if(widgetName=="toutaoxuanze/juyuan")
	{
		g_userInformation.setHeadMode("duck.mesh");

	}else if(widgetName=="toutaoxuanze/danlanyuan")
	{
		g_userInformation.setHeadMode("head_tu.mesh");	
		
	}else if(widgetName=="toutaoxuanze/hongyuan")
	{
		g_userInformation.setHeadMode("xiaoji.mesh");
		
	}else if(widgetName=="toutaoxuanze/lanlvyuan")
	{	
			g_userInformation.setHeadMode("hema.mesh");

	}else if(widgetName=="toutaoxuanze/lanyuan")
	{
			g_userInformation.setHeadMode("deer.mesh");
 
	}else if(widgetName=="toutaoxuanze/huangyuan")
	{	
		   g_userInformation.setHeadMode("mouse.mesh");	
		
	}


	///ѡ����ͷ�׽���ѡ�����ͽ���
	setVisible(false);
	UIBase* pSelectFace=Application::getSingleton().getUIByName("lianxingxuze");
	pSelectFace->setVisible(true);


	return ;

}