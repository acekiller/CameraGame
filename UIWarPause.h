/*******************************************
��Ϸ��ʱ����
**********************************************/

#pragma once

#include "UIBase.h"


class UIWarPause :public	UIBase
{

public:

	UIWarPause();


	~UIWarPause();


	void init();

	void setVisible(bool b);


protected:

///��ť�ص��¼�
   virtual void buttonHit(Widget* button);


protected:
	Widget* m_pReturn ;
	Widget* m_pContinue;




};