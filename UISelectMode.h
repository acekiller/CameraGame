
#pragma  once

#include "UIBase.h"
#include "UILLayout.h"



class UISelectMode :public UILayout
{


public:

	UISelectMode();

	~UISelectMode();




	/**��ʼ��*/
	//virtual void init();



protected:


	///�����ť�ص�����
	virtual void buttonHit(Widget* button);





};