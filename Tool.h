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
    
    
#if OGRE_PLATFORM ==OGRE_PLATFORM_IPHONE
   // static  Ogre::String           getIphoneDocumentPath();
#endif
    
    
    
};