/**************************************************
ѡ���û��������ͽ��档�������ʵ����3d����,ѡ����������ģ��
**************************************************/



#include "UIBase.h"



class SelectFaceMode :public UIBase
{
public:


	
	SelectFaceMode();


	~SelectFaceMode();




protected:

	void init();


	/**�����Ƿ�ɼ�*/
	virtual void  setVisible(bool b);


	/**�ж��Ƿ�ɼ�,�����ͬ������Ӧ��ָ�¼�*/
	virtual bool   isVisible()const ;






};