
/*****************************************************************
����ؼ��ķ�װ
*********************************************************************/





#pragma  once


#include "SdkTrays.h"



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


	~StaticImage();


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