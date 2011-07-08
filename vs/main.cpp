
/************************************************

window ��ں���
**************************************************/






#include "pch.h"
#include "Application.h"




INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
{
	


	
	//��õ�ǰ����Ŀ¼
	char pBuffer[1024];
	ZeroMemory(pBuffer, 1024);
	GetModuleFileName(NULL, pBuffer, 1024);

	//���õ�ǰĿ¼Ϊ����Ŀ¼����ֹͨ���ļ������򿪳���ĵ�ǰĿ¼����ȷ
	Ogre::String dirname,filename,extname;
	Ogre::String cc=pBuffer;

	Ogre::StringUtil::splitFullFilename(cc , filename , extname , dirname);
	SetCurrentDirectory(dirname.c_str());
	//////////////////////////////////////////////////////////////////////////



	try
	{

		Application* pApp= new  Application();
		pApp->go();
		delete Application::getSingletonPtr();

	}
	catch(std::exception &e)
	{
		//MessageBox(NULL, e.getFullDescription().c_str(), "Exception", MB_OK | MB_ICONERROR | MB_TASKMODAL);
		MessageBox(NULL, e.what(), "Exception", MB_OK | MB_ICONERROR | MB_TASKMODAL);
		
	}


	return 0;
}




