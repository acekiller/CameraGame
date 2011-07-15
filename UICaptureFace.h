//
//  UICaptureFace.h
//  ogreApp
//
//  Created by thcz on 11-7-7.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//
/****************************************
 ������������
*****************************************/

#include "UIBase.h"



class ImageButton;


class UICaptureFace :public UIBase
{
    
public:
    
    UICaptureFace();
    
    
    ~UICaptureFace();


	/**��ʼ��*/
	virtual void init();


	///�����Ѿ��ж��ٸ��û���
	void setUserCount(unsigned int count);
    

    
    
protected:
    

	/**��ʼ����,*/
	virtual void onBeginTouch(int x,int y);


	/**������ָ*/
	virtual void onMoveTouch(int x,int y);


	/**��ָ�뿪*/
	virtual void onEndTouch(int x,int y);



	virtual void buttonHit(Button* button);
    
    

protected:

	///ʵ�л�ui
	void  initUI();

	///ȥ��ui
	void  destroyUI();



	///��ť�ص��¼�
	virtual void buttonHit(Widget* button);



  ///���ص�

	ImageButton* m_pToUserFace;///�����û�ѡ��ť

	ImageButton* m_pGoBackButton;///���ذ�ť

	ImageButton* m_pCaptureButton;///���հ�ť


	///��ǰ�Ѿ������˶��ٸ��û�
	unsigned int  m_UserCount;
    
};