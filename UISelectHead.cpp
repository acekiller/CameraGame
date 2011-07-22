

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


	//Image3DButton* pImageButton=new Image3DButton("TestButton",pScenNode);
	//registerWidget(pImageButton);

	SliderGallery* pSliderGallery=new SliderGallery("testSliderGallery",new FaceModeDataSource());
	registerWidget(pSliderGallery);
	pSliderGallery->getOverlayElement()->setHorizontalAlignment(Ogre::GHA_LEFT);
	pSliderGallery->getOverlayElement()->setLeft(100);



	m_pReturnButton=new ImageButton("SelectHeadReturn","sdk_button_down.png","sdk_button_up.png");
	m_pReturnButton->setHorizontalAlignment(Ogre::GHA_LEFT);
	m_pReturnButton->setVerticalAlignment(Ogre::GVA_TOP);
	m_pReturnButton->setLeft(700);
	m_pReturnButton->setTop(400);
	registerWidget(m_pReturnButton);




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