

/***********************************************
��Ϸ��ʼ���档���play��ʼ��Ϸ��
*************************************************/


#include "UIBase.h"


class Widget;

class UIGamePlay :public UIBase
{
public:

	UIGamePlay();


	~UIGamePlay();



	/**��ʼ��*/
	virtual void init();

	//virtual void update(float time);



protected:


	/**�����ť�ص��¼�*/
	virtual void buttonHit(Widget* button);



	



};