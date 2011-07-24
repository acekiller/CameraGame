

#include "pch.h"
#include "UISelectHead.h"
#include "Widget.h"
#include "Application.h"
#include "Tool.h"




FaceModeDataSource::FaceModeDataSource()
{

	m_ElementCollect.push_back(std::make_pair("texture1.png","userdata1"));
	m_ElementCollect.push_back(std::make_pair("texture2.png","userdata2"));
    m_ElementCollect.push_back(std::make_pair("texture3.png","userdata3"));
	m_ElementCollect.push_back(std::make_pair("texture4.png","userdata4"));
	m_ElementCollect.push_back(std::make_pair("texture5.png","userdata5"));
	m_ElementCollect.push_back(std::make_pair("texture6.png","userdata6"));
	m_ElementCollect.push_back(std::make_pair("texture7.png","userdata7"));
    m_ElementCollect.push_back(std::make_pair("texture8.png","userdata8"));
	m_ElementCollect.push_back(std::make_pair("texture9.png","userdata9"));
	m_ElementCollect.push_back(std::make_pair("texture10.png","userdata10"));
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

	textureName=m_ElementCollect[index].first;
	return true;

}

	/**��ȡԪ�ص��û�����
	*�ɹ�����true ʧ�ܷ���false
	*/
bool FaceModeDataSource::getElementUserData(unsigned index,Ogre::String& elementData)
{

	if(index>=m_ElementCollect.size())
		return false;

	elementData=m_ElementCollect[index].second;
	return true;

}







//---------------------------------------------------------------
UISelectHead:: UISelectHead()
:UIBase("UISelectHead",""),m_pReturnButton(NULL)
{


}


//---------------------------------------------------------------
 UISelectHead::~ UISelectHead()
{


}


//---------------------------------------------------------------
void  UISelectHead::init()
{

	UIBase::init();

	//Ogre::SceneManager* pSceneMrg=Application::getSingleton().getMainSceneManager();
	//Ogre::Entity* pHead=pSceneMrg->createEntity("Head.mesh");
	//Ogre::SceneNode* pScenNode=  pSceneMrg->getRootSceneNode()->createChildSceneNode();
	//pScenNode->attachObject(pHead);


	StaticImage* pImage=new StaticImage("SelectHeadBackGround","tuku_background.png");
	registerWidget(pImage);
	Ogre::OverlayElement* pElment=pImage->getOverlayElement();
	pImage->setMetricsMode(Ogre::GMM_RELATIVE);
	pImage->setHorizontalAlignment(Ogre::GHA_LEFT);
	pImage->setVerticalAlignment(Ogre::GVA_TOP);
	pImage->setLeft(0.0f);
	pImage->setWidth(1.0f);
	pImage->setTop(0.0f);
	pImage->setHeight(1.0f);



	SliderGallery* pSliderGallery=new SliderGallery("SelectHeadSliderGallery",new FaceModeDataSource());
	registerWidget(pSliderGallery);
	pSliderGallery->getOverlayElement()->setHorizontalAlignment(Ogre::GHA_LEFT);
	//pSliderGallery->getOverlayElement()->setLeft();



	m_pReturnButton=new ImageButton("SelectHeadReturn","moshi_fanhui_press.png","moshi_fanhui_release.png");
	m_pReturnButton->setHorizontalAlignment(Ogre::GHA_LEFT);
	m_pReturnButton->setLeft(10);
	m_pReturnButton->setVerticalAlignment(Ogre::GVA_BOTTOM);
	m_pReturnButton->setTop(-128);
	registerWidget(m_pReturnButton);





	//���ذ�ť



}


//----------------------------------------------------------------
void  UISelectHead::sliderGalleryhit(SrollButton* pbutton)
{

	Ogre::String userData=pbutton->getUserData();


	///ѡ����ͷ�׽���ѡ�����ͽ���
	setVisible(false);
	UIBase* pSelectFace=Application::getSingleton().getUIByName("UISelectFaceMode");
	pSelectFace->setVisible(true);


	return ;

}

void UISelectHead::buttonHit(Widget* pWidget)
{
	if(pWidget==NULL)
		return ;


	//���ذ�ť���ص�ѡ���������
	if(pWidget==m_pReturnButton)
	{

		Ogre::StringVectorPtr pUserList=Tools::getUserFaceFileList();

		if(pUserList.isNull()||pUserList->empty())///���û����Ϣ�ͷ��ص���������
		{
		   
			UIBase* pUI=Application::getSingletonPtr()->getUIByName("CaptureFaceUI");
		    pUI->setVisible(true);
	
     	}else///���ص�ѡ���û��Ľ���
		{

			UIBase* pUI=Application::getSingletonPtr()->getUIByName("UISelectUser");
			pUI->setVisible(true);
		}
         setVisible(false);

		return ;

	}

}