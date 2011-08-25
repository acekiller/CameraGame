/*****************************************************


*******************************************************/



#pragma  once


#include "UIImage.h"
#include "rapidxml.hpp"





class UIImageSet
{

	friend class UIImagesetManager;
protected:

	/**���캯��
	*@filename imageset�ļ���
	*/
	UIImageSet(const Ogre::String& fileName,const Ogre::String& resourceGroup);

	~UIImageSet();
public:


	/**����imageset���ļ���*/
	const Ogre::String& getFileName()const {return m_FileName;}

	/**����imageset����*/
	const Ogre::String& getName()const;

	/**��ȡ��Ӧ����ͼ�ļ���*/
	const Ogre::String& getTextureName()const {return m_TextureName;}


	/**��ȡָ����image.���û�з��ؿ�*/
	Image*  getImageByName(const Ogre::String& name)const ;


	/**��ȡimage������*/
	unsigned  int getImageCount()const;

	/**��ȡָ��������image�����û�з��ؿ�*/
	Image*   getImageByIndex(unsigned int index)const;




protected:

	/**����һ��image*/
	bool       addImage(Image* pImage);

	/**ɾ�����е�image*/
	void       destroyAllImage();

	/** xml��غ���
	@{*/

	Ogre::String getAttrib(rapidxml::xml_node<>* XMLNode, const Ogre::String &parameter, const Ogre::String &defaultValue = "");

	Ogre::Real getAttribReal(rapidxml::xml_node<>* XMLNode, const Ogre::String &parameter, Ogre::Real defaultValue = 0);

	bool getAttribBool(rapidxml::xml_node<>* XMLNode, const Ogre::String &parameter, bool defaultValue = false);


	/**����imaset set*/
	bool processImageset(rapidxml::xml_node<>* XMLRoot,const Ogre::String& resourceGroup);

	/**����image*/
	bool processImage(rapidxml::xml_node<>* XMLRoot);


	/**@}*/

	Ogre::String      m_Name;

	Ogre::String      m_FileName;    ///��Ӧ��image�ļ���

	Ogre::String      m_TextureName;///��Ӧ��ͼƬ��

	Ogre::Vector2     m_Rect;       ///ͼƬ�Ĵ�С

	UIImageCollect    m_ImageCollect; ///����image�ļ���

	Ogre::TexturePtr  m_pOgreTexture;

	



};


