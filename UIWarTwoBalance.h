/************************************
ģʽ2�Ľ������
************************************/


#include "UIBase.h"
#include "UILLayout.h"

class WarMode;
class StaticImage;

class UIWarTowModeBalance :public UILayout
{

public:

	UIWarTowModeBalance(WarMode* pWarMode);

	~UIWarTowModeBalance();


	/**���÷���*/
	void setScore(unsigned int    score);

	void init();

	/**���÷���Ϊ0*/
	void resetScore();
	
protected:


	///��������
	void destroy();


	///��ť�ص��¼�
	virtual void buttonHit(Widget* button);




protected:

	WarMode* m_pWarMode;

	StaticImage* m_Score[5];

};
