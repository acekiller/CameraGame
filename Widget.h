
/*****************************************************************
����ؼ��ķ�װ
*********************************************************************/





#pragma  once


#include "SdkTrays.h"



class Ogre::OverlayElement;

/**
ͼƬ��ť
*/
class ImageButton :public Widget
{

public:


	/**���캯��
	*@name                �ؼ���
	*@param normalTexture ����װ̬�µ�ͼƬ
	*@param pressTexture  ��ָ���µ�ͼƬ
	*/
	ImageButton( const Ogre::String& name,const Ogre::String& normalTexture,const Ogre::String& pressTexture);


	virtual ~ImageButton();


protected:


	virtual void _cursorPressed(const Ogre::Vector2& cursorPos);

	virtual void _cursorReleased(const Ogre::Vector2& cursorPos) ;

	virtual void _focusLost();



	/**����״̬ˢ����ʾ*/
	void updateState();



protected:


	 Ogre::String m_NormalTexture;
	 Ogre::String m_PressTexture;

	 Ogre::MaterialPtr m_pMaterial;

	 ButtonState       m_State;



};




/******************************************************************
��̬ͼƬ�ؼ�
*******************************************************************/
class StaticImage : public Widget
{

public:


	
	/**���캯��
	*@param  textureName ��ͼ�ļ���
	*/
	StaticImage(const Ogre::String& name, const Ogre::String& textureName);


    virtual	~StaticImage();


	void setImage(const Ogre::String& textureName);


protected:

	Ogre::MaterialPtr m_pMaterial;


};




/*********************************************
����ͼƬ��ť,����ʱ�䳬��ָ��ʱ��ᷢ���¼�
**************************************************/

class TimeImageButton:public Widget
{

public:
	enum TIB
	{

		NORMAL,///����״̬
		Press,///��������״̬����ʱ����ּ��ŷ�


	};

public:
	TimeImageButton(const Ogre::String&name, const Ogre::String& imageName);

	~TimeImageButton();


	virtual void update(float time);


	virtual void _cursorPressed(const Ogre::Vector2& cursorPos);

	virtual void _cursorReleased(const Ogre::Vector2& cursorPos) ;

	virtual void _focusLost();



	///����״̬
	void reset();

	TIB getState()const{return m_State;}
    
    
    
    


protected:

	///����״̬������ʾ
	void updateState();
    
    ///ҡ����ť
    void rotateButton(float time);



	float m_Time;///�����೤ʱ��
	float m_CurrentTime;//��ʱ��ʱ
	TIB   m_State;
	bool  m_isPress;///�Ƿ���

	Ogre::MaterialPtr m_pBackgroundMaterial;
	Ogre::MaterialPtr m_pDeleteMaterial;

	Ogre::OverlayElement* m_pDeleteElement;///ɾ����ť
    

};



/***********************************************
����ʾ3dͼ�εİ�ť�����԰�һscenenode�ҵ������ť��
**************************************************/
class Image3DButton :public Widget
{
public:

	Image3DButton(const Ogre::String& name,Ogre::SceneNode* pNode);


	~Image3DButton();


    /**���ù��صĽڵ�*/
	void   setSceneNode(Ogre::SceneNode* pNode);

	virtual void _cursorPressed(const Ogre::Vector2& cursorPos);

	virtual void _cursorReleased(const Ogre::Vector2& cursorPos) ;


	///��������
	virtual const Ogre::String& getName();


protected:

	Ogre::Overlay*  m_pOveraly;

	Ogre::SceneNode* m_pScenNode;

	 

};



/*************************************************
������ť��
****************************************************/

///������ť������Դ
class 	SliderGalleryDataSource
{
public:
	SliderGalleryDataSource(){}


	virtual ~SliderGalleryDataSource(){}


	/**��ȡ���ж��ٸ�Ԫ��
	*/
	virtual	unsigned int getElementCount()=0;


	/**��ȡԪ�ص���ͼ��
	*�ɹ�����true ʧ�ܷ���false
	*/
	virtual bool  getElementTexture(unsigned int index,Ogre::String& textureName)=0;



	/**��ȡԪ�ص��û�����
	*�ɹ�����true ʧ�ܷ���false
	*/
	virtual bool getElementUserData(unsigned index,Ogre::String& elementData)=0;


};


///�����������ÿһ����ť
class SrollButton
{

public:

	SrollButton(Ogre::OverlayElement* pElement)
		:m_pElement(pElement),m_OriginalPos(0.0f),m_targetPos(0.0f),m_Visible(false)
	{

		Ogre::MaterialPtr pMat=pElement->getMaterial();
		assert(pMat.isNull()==false);
		pMat= pMat->clone(pElement->getName());
		pElement->setMaterialName(pMat->getName());
		m_OriginaWidth=pElement->getWidth();
		m_TargetWidth=m_OriginaWidth;

		m_OriginaHeight=pElement->getHeight();
		m_TargetHeight=m_OriginaHeight;

		m_OriginaZOrder=pElement->getZOrder();
		m_TargetZorder=m_OriginaZOrder;

		return;

	}

	/**��������*/
	void sroll(float precent)
	{
		if(m_pElement==NULL)
			return ;
		if(precent>=1.0f)
		{
			m_pElement->setLeft(m_targetPos.x);
			m_pElement->setTop(m_targetPos.y);
			m_pElement->show();
			return ;
		}

		m_pElement->setLeft(m_OriginalPos.x+(m_targetPos.x-m_OriginalPos.x)*precent);
		m_pElement->setTop(m_OriginalPos.y+(m_targetPos.y-m_OriginalPos.y)*precent);
		m_pElement->setWidth(m_OriginaWidth+(m_TargetWidth-m_OriginaWidth)*precent);
		m_pElement->setHeight(m_OriginaHeight+(m_TargetHeight-m_OriginaHeight)*precent);
		//m_pElement->getZOrder()
		

		

		
		
		if(m_Visible)
		{
			m_pElement->show();
		}else
		{
			m_pElement->hide();

		}
		return ;

	}


	/**���ð�ť��ͼƬ
	*/
	void setTextureName(const Ogre::String& textureName)
	{
		if(m_pElement==NULL)
			return ;
		m_pElement->getMaterial()->getTechnique(0)->getPass(0)->
			getTextureUnitState(0)->setTextureName(textureName);


	}


	/**�����û�����
	*/
	void setUserData(const Ogre::String& data)
	{
		m_userData=data;
	}


	/**�����û�����
	*/
	const Ogre::String getUserData()const
	{
		return m_userData;
	}


	/**�ж�������ڰ�ť�ķ�Χ
	*/
	bool isCursorOver(const Ogre::Vector2& pos)
	{
		if(m_pElement==NULL)
			return false;
		if(m_pElement->isVisible()==false)
			return false;

		return Widget::isCursorOver(m_pElement,pos);


	}


	///�����Ƿ�ɼ�
	void setVisible(bool b)
	{
		if(m_pElement!=NULL)
		{
			if(b)
			{
            	m_pElement->show();				
			}else
			{

				m_pElement->hide();
			}

		}
	}


public:

	Ogre::OverlayElement*  m_pElement; 
	Ogre::Vector2          m_OriginalPos; ///������ʼ��λ�� 
	Ogre::Vector2          m_targetPos;   ///�����᲻��λ��

	int                    m_OriginaWidth;//��
	int                    m_TargetWidth;

	int                    m_OriginaHeight;//��
	int                    m_TargetHeight;

	int                    m_OriginaZOrder;  //z˳��
	int                    m_TargetZorder; 


	bool                   m_Visible;     ///�����Ƿ�����
	Ogre::String           m_userData;     ///�û���������



};


class SliderGallery : public Widget
{

public:



public:

	SliderGallery(const Ogre::String& name,SliderGalleryDataSource* pDataSource);
 
   virtual	~SliderGallery();


   /**��������Դ*/
   void setDataSource(SliderGalleryDataSource* pSource);



protected:

	/**���ص��¼�
	*/
	virtual void _cursorPressed(const Ogre::Vector2& cursorPos);

	/**���ص��¼�
	*/
	virtual void _cursorReleased(const Ogre::Vector2& cursorPos) ;

	/**���ص��¼�
	*/
	virtual void _cursorMoved(const Ogre::Vector2& cursorPos);




protected:


	///ÿ֡���º���
	void update(float tim);


	///��ǰ����һ��
	void previsouButton();


	///������һ��
	void nextButton();

	///��ȡ���а�ťԭ����λ��
	void saveButtonPos() ;

	///ɾ�����еĹ�����ť
	void destroySrollButton();


	///ˢ������button����
	void resetButtonInformation();


	///��������
	void endRoll();


	///�������ҹ�����ť״̬
	void updateSrollButton();


	protected:

	
	Ogre::OverlayElement* m_pPrevisouButton;///��ǰһ����ť

	Ogre::OverlayElement* m_pNextButton; ///���һ����ť



	typedef std::vector<SrollButton*> SrollButtonCollect;
	SrollButtonCollect         m_ButtonCollect; ///��¼�������еİ�ť


	bool                  m_IsPress;         ///�Ƿ���
	int                   m_RollDir;        ///�������� 0,��ʾ��������-1�����һ�� 1����·����һ��
	float                 m_RollTime;       ///����ʱ��




	SliderGalleryDataSource*      m_pDataSource; ////����Դ
	unsigned int                  m_DataIndex; ///����߰�ť��Ӧ����Դ��ڼ�������


};


/*************************************************
����ת�ľ�̬ͼƬ
****************************************************/
class RotateImage :public StaticImage
{

public:
	RotateImage(const Ogre::String& name, const Ogre::String& imageName);

	~RotateImage();

	/**���ó���
	*@param radian ���ȵ�λ
	*/
	void setOrientation(float radian);


	void update(float time);

protected:

	


};