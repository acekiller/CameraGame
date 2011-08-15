/***************************************************
ѡ��ͷ��ģ�ͽ���
*****************************************************/



#pragma  once

#include "UIBase.h"
#include "Widget.h"




class FaceModeDataSource :public SliderGalleryDataSource
{

public:

	FaceModeDataSource();


	virtual ~FaceModeDataSource();



protected:

	/**��ȡ���ж��ٸ�Ԫ��
	*/
	virtual	unsigned int getElementCount();


	/**��ȡԪ�ص���ͼ��
	*�ɹ�����true ʧ�ܷ���false
	*/
	virtual bool  getElementTexture(unsigned int index,Ogre::String& textureName);

	/**��ȡԪ�ص��û�����
	*�ɹ�����true ʧ�ܷ���false
	*/
	virtual bool getElementUserData(unsigned index,Ogre::String& elementData);


protected:

	typedef std::vector< std::pair<Ogre::String ,Ogre::String >  > ElementCollect;
	ElementCollect m_ElementCollect;



};










class UISelectHead :public UIBase
{



public:

	 UISelectHead();

	~ UISelectHead();







protected:


	/**��ʼ��*/
	virtual void init();


	/**���������ť�ص�����*/
	 virtual void sliderGalleryhit(SrollButton* pbutton);



	 ///�����ť�ص��¼�
     void  buttonHit(Widget* pWidget);



protected:



	Widget* m_pReturnButton;




};