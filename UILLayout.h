
/***********************************************
��һ��layout�ļ��ж�����沼��
*************************************************/
#pragma once 

#include "UIBase.h"
#include "rapidxml.hpp"

class UILayout :public UIBase
{

public:

	UILayout(const Ogre::String& fileName);


	~UILayout();


	virtual void init();


protected:


	/**����layout�ļ���غ���
	*@{
	*/

	/**
	*@param fileName ����layout�ļ���
	*@return �ɹ������档ʧ�ܷ��ؼ�
	*/
	bool loadLayoutFile(const Ogre::String& fileName);


	/**���������*/
	bool processRootWindow(rapidxml::xml_node<>* pNode);

	/**������*/
	bool processWindow(rapidxml::xml_node<>* pNode);

	/**��������*/
	bool processProperty(rapidxml::xml_node<>* pNode);


	/**��ȡ��ǰ�ڵ��µ�property���ӽڵ��ֵ
	@return �ɹ������档ʧ�ܷ��ؼ�
	*/
	bool  getChildProperty(rapidxml::xml_node<>* pNode,const Ogre::String& propertyName, Ogre::String& Value);


	/**��cegui�ľ������ʹ�ת��ogre overlay������*/
	bool  ConvertCEGUIRectToOgre(const Ogre::String& CEGUICoord,Ogre::Vector4& rect);


	/**@}
	*/




};