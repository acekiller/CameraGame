#include "UIBase.h"


class Widget;

class UIWarone :public UIBase
{

public:

	UIWarone();

	~UIWarone();


	virtual void init();


protected:


	/**��ť�ص��¼�*/
	virtual void buttonHit(Widget* button);




protected:

	Widget* m_PauseButton;

	Widget* m_FirePoint;




};