#include "UIBase.h"
#include "UILLayout.h"


class Widget;
class StaticImage;

class UIWarone :public UILayout
{

public:

	UIWarone();

	~UIWarone();


	/**��ʼ��*/
	virtual void init();

	/**����ʱ��
	*@param time ��ʣ������
	*/
	void setTime(int time);


protected:


	/**��ť�ص��¼�*/
	virtual void buttonHit(Widget* button);




protected:

//	Widget*        m_PauseButton;     ///��ͣ��ť
	//Widget*        m_FirePoint;       ///׼��ͼ��

	StaticImage*        m_HundredTime;     ///����
	StaticImage*        m_TenTime;          ///ʮ��
	StaticImage*        m_DigitTime;        ///��λ����




};