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
#include "UILLayout.h"


class ImageButton;


class UICaptureFace :public UILayout
{
    
public:
    
    UICaptureFace();
    
    
    ~UICaptureFace();


	/**��ʼ��*/
	virtual void init();


	///�����Ѿ��ж��ٸ��û���
	void setUserCount(unsigned int count);
    
    /**�����Ƿ�ɼ�*/
    virtual void  setVisible(bool b);

    
    
protected:
    
    
   
    

protected:

	
	///��ť�ص��¼�
	virtual void buttonHit(Widget* button);



  ///���ص�

//	ImageButton* m_pToUserFace;///�����û�ѡ��ť

	//ImageButton* m_pGoBackButton;///���ذ�ť

	Widget* m_pCaptureButton;///���հ�ť


	///��ǰ�Ѿ������˶��ٸ��û�
	unsigned int  m_UserCount;


	Widget*       m_pFullWidget;

      




    
};