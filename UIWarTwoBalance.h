/************************************
ģʽ2�Ľ������
************************************/


#include "UIBase.h"
#include "UILLayout.h"

class WarMode;

class UIWarTowModeBalance :public UILayout
{

public:

	UIWarTowModeBalance(WarMode* pWarMode);

	~UIWarTowModeBalance();


	//void init();
	
protected:


	///��������
	void destroy();


	///��ť�ص��¼�
	virtual void buttonHit(Widget* button);




protected:

	WarMode* m_pWarMode;


};
