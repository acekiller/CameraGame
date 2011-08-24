//
//  Tool.h
//  ogreApp
//
//  Created by thcz on 11-7-6.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//

#pragma once

/**
 �����࣬һ�㶼�Ǿ�̬���������һЩͨ�ù��� 
*/

#include "rapidxml.hpp"


class Tools
{
 
public:
    Tools();

    ~Tools();

    
    
    
    /**����һ��overlay�����Ӷ���*/
    //static  void DestroyOverlayAndChild(Ogre:::Over);
    
    
    /**��ȡ�����Ѿ�������û�*/
    static  Ogre::StringVectorPtr getUserFaceFileList();
    
    
    ///��ȡ�û�����󱣴��·��
    static Ogre::String       getUserFacePath();
    
    ///������ת��image��
    static void ConverTextureToImage(Ogre::TexturePtr pTexture,Ogre::Image& image);
    
    /**����ogre��ͼ�ļ���ָ��Ŀ¼��
        *@remark ptexture ����iphone�±���ΪHBU_DYNAMIC_WRITE_ONLY ������
       */
    static bool  saveOgreTexture(const char* fileName,Ogre::TexturePtr pTexture);
    
    

    
    /**������Ļ����
	*@param pTexture ������rendetTarget��־��������ͼ
	*/
	static bool  getScreenSnapshot(Ogre::TexturePtr pTexture);
    
    
    
    

   // static bool testSaveTexture(const Ogre::String& fileName);
    
    


   // static  Ogre::String           getIphoneDocumentPath();
     static bool  saveOgreTextureToPhotosAlbum(Ogre::TexturePtr pTexture);

    
    

	 /**��һ�����뵥λת��Сʱ���֡����ʽ
	 *@param t ����
	 */
	static void  parseTime(unsigned int t,unsigned int& hourcs,unsigned int& minutes,unsigned int& seconds);

    
	/**
	* Desc:  ���һ������ָ��λ��ֵ
	* @param value ����ֵ
	* @param bit ��Ҫָ����λ������λ����1��ʮλ����2����λ����3....
	* return : ����ָ��λ��ֵ
	*/
	 static int getValueByBit(int value , int bit);



	 static Ogre::String getAttrib(rapidxml::xml_node<>* XMLNode, const Ogre::String &attrib, const Ogre::String &defaultValue)
	 {
		 if(XMLNode->first_attribute(attrib.c_str()))
			 return XMLNode->first_attribute(attrib.c_str())->value();
		 else
			 return defaultValue;
	 }

	 static float  getAttribReal(rapidxml::xml_node<>* XMLNode, const Ogre::String &attrib,float  defaultValue)
	 {
		 if(XMLNode->first_attribute(attrib.c_str()))
			 return Ogre::StringConverter::parseReal(XMLNode->first_attribute(attrib.c_str())->value());
		 else
			 return defaultValue;
	 }

	 static bool getAttribBool(rapidxml::xml_node<>* XMLNode, const Ogre::String &attrib, bool defaultValue)
	 {
		 if(!XMLNode->first_attribute(attrib.c_str()))
			 return defaultValue;

		 if(Ogre::String(XMLNode->first_attribute(attrib.c_str())->value()) == "true")
			 return true;

		 return false;
	 }


    
};