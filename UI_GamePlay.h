

/***********************************************
��Ϸ��ʼ���档���play��ʼ��Ϸ��
*************************************************/


#include "UIBase.h"
#include "UILLayout.h"

class Widget;

class UIGamePlay :public UILayout
{
public:

	UIGamePlay();


	~UIGamePlay();



	/**��ʼ��*/
	//virtual void init();

	//virtual void update(float time);



protected:


	/**�����ť�ص��¼�*/
	virtual void buttonHit(Widget* button);



	



};