//
//  Config.h
//  ogreApp
//
//  Created by thcz on 11-7-7.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//


/**************************
 ��Ϸ�������ȫ�ֱ��������ڴ˴�
 *************************/


#pragma  once

#include "UserInformation.h"



///ui overlay ���涨������·��

#if OGRE_PLATFORM ==OGRE_PLATFORM_IPHONE

const  static std::string g_UIPath="Media/CameraGame/UI/";
const  static std::string g_UserFacePath="/UserFace";
const  static std::string g_EnemyFormat="Media/EnemyFormat.cfg";///���������ļ�


#else


const  static std::string g_UIPath="../../../Media/CameraGame/UI/";
const  static std::string g_UserFacePath="../../../Media/CameraGame/UserFace";
const  static std::string g_EnemyFormat="../../../Media/EnemyFormat.cfg";


#endif




///�û���Ƭ����ĸ�ʽ
static  const  std::string g_UserFaceFormt=".png";

///�û�ѡ����Ϣ
static UserInformation g_userInformation;

///���ܱ�����Ŀ�������
static const   Ogre::String  m_FriendFaceImage="";
