/***************************
��ʾ֡���͵�����Ϣ����
**************************/
#include "UIBase.h"

class ParamsPanel;
class Label;

class UIDebug :public UIBase
{
public:

	UIDebug();

	~UIDebug();


	virtual void  init();

	virtual void update(float time);



protected:

	ParamsPanel*  m_pParamsPanel;                  //��������
	Label*        m_pFpsLabel;                     // FPS label



};