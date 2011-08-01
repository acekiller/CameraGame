/******************************************
��Ϸģʽ������
*******************************************/


#include "UIBase.h"
#include "Widget.h"


class WarModeThree;


///��������Դ
class ItemDataSource :public SliderGalleryDataSource
{
public:

	ItemDataSource()
	{
		m_Collect.push_back(std::make_pair("model3__egg_press.png","egg"));
		m_Collect.push_back(std::make_pair("model3__brick_press.png","egg"));
		m_Collect.push_back(std::make_pair("model3__shoes_press.png","egg"));
		m_Collect.push_back(std::make_pair("model3__knife_press.png","egg"));
		m_Collect.push_back(std::make_pair("model3__baseball_press.png","egg"));
		m_Collect.push_back(std::make_pair("model3__baseball_press.png","egg"));
		m_Collect.push_back(std::make_pair("model3__baseball_press.png","egg"));
		
	}


	~ItemDataSource(){}


	
	/**��ȡ���ж��ٸ�Ԫ��
	*/
	virtual	unsigned int getElementCount()
	{
		return m_Collect.size();
	}


	/**��ȡԪ�ص���ͼ��
	*�ɹ�����true ʧ�ܷ���false
	*/
	virtual bool  getElementTexture(unsigned int index,Ogre::String& textureName)
	{
		if(index>=m_Collect.size())
			return false;
		textureName=m_Collect[index].first;
		return true;

	}



	/**��ȡԪ�ص��û�����
	*�ɹ�����true ʧ�ܷ���false
	*/
	virtual bool getElementUserData(unsigned index,Ogre::String& elementData)
	{

		if(index>=m_Collect.size())
			return false;
		elementData=m_Collect[index].second;
		return true;
	
	}



protected:

		typedef std::vector< std::pair<Ogre::String ,Ogre::String >  > ItemCollect;
		ItemCollect    m_Collect;


};







class UIWarModeThree : public UIBase
{

public:

	UIWarModeThree(WarModeThree* pWarMode);


	~UIWarModeThree();


	void init();


	/**���õ�ǰ�����۵İٷֱ�
	*@percent �ٷֱȡ�0--1֮ǰ
	*/
	void setPowerPercent(float percent);


	//void update(float time);


	/**����ؼ��¼�*/
	void sliderGalleryhit(SrollButton* pbutton );///��������ťѡ���¼�

	void buttonHit(Widget* button);


	/**��ȡ��ǰuiѡ��ĵ������� */
	const Ogre::String& getCurrentItemType()const {return m_ItemType;}


protected:


	/**��ʼ����,������߾�*/
	//virtual void onBeginTouch(int x,int y);



	WarModeThree*        m_pWarMode;    ///��Ӧ��ս��ģʽ

	Widget*              m_pPauseButton;//��ͣ��ť
	StaticImage*         m_pPowerBackground;///�����۱���
	StaticImage*         m_pPowerImage;     ///������ͼƬ

	Widget*              m_pSnapshotButton;//��������
	SliderGallery*       m_pItemSelectSlider;///ѡ����߹����ؼ�

	Ogre::String         m_ItemType;



};