
/***************************************************
ս��ģʽ2��ui����
*******************************************************/



#pragma  once


#include "UIBase.h"



class RotateImage;

class UIWarModeTwo :public UIBase
{

public:


	UIWarModeTwo();


	~UIWarModeTwo();


	 void init();





	 ///���õ������еķ���
	 void setEmemeyDir(float Radian);

protected:



      RotateImage* m_pRotateImage;//ָ����˵ķ���


};