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


	/**�����Ƿ�ɼ�*/
	void setVisible(bool b);


	/**���õ���ͣ��������Ҫ��ʾ�Ľ���*/
	void setEndShowUI(const std::vector<UIBase*>& UIList){m_ContinueShowUI=UIList;}


protected:

///��ť�ص��¼�
   virtual void buttonHit(Widget* button);


protected:
	Widget* m_pReturn ;
	Widget* m_pContinue;

	///
	std::vector<UIBase*> m_ContinueShowUI;




};