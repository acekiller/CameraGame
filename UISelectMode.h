
#pragma  once

#include "UIBase.h"




class UISelectMode :public UIBase
{


public:

	UISelectMode();

	~UISelectMode();




	/**��ʼ��*/
	virtual void init();



protected:


	///�����ť�ص�����
	virtual void buttonHit(Widget* button);





};