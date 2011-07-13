
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