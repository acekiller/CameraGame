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




///ui overlay ���涨������·��

#if OGRE_PLATFORM ==OGRE_PLATFORM_IPHONE

const  static std::string g_UIPath="Media/CameraGame/UI/";

#else

const  static std::string g_UIPath="../../../Media/CameraGame/UI/";

#endif