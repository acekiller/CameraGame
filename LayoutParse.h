/*******************************************************

�������沼����

***********************************************************/




#pragma once


class UIBase;


class LayoutParse
{


public:

	LayoutParse();



	 ~LayoutParse();



	 /**���������ļ���ʧ�ܷ��ؼ�*/
	 UIBase*  parse(const Ogre::String& fileName);





};