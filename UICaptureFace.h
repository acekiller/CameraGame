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





class UICaptureFace :public UIBase
{
    
public:
    
    UICaptureFace();
    
    
    ~UICaptureFace();


	/**��ʼ��*/
	virtual void init();
    

    
    
protected:
    

	/**��ʼ����,*/
	virtual void onBeginTouch(int x,int y);


	/**������ָ*/
	virtual void onMoveTouch(int x,int y);


	/**��ָ�뿪*/
	virtual void onEndTouch(int x,int y);



	virtual void buttonHit(Button* button);
    
    
    
};