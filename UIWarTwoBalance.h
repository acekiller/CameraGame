/************************************
ģʽ2�Ľ������
************************************/


#include "UIBase.h"

class WarMode;

class UIWarTowModeBalance :public UIBase
{

public:

	UIWarTowModeBalance(WarMode* pWarMode);

	~UIWarTowModeBalance();


	void init();
	
protected:


	///��������
	void destroy();


	///��ť�ص��¼�
	virtual void buttonHit(Widget* button);




protected:

	WarMode* m_pWarMode;


};
