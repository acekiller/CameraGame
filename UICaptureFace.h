//
//  UICaptureFace.h
//  ogreApp
//
//  Created by thcz on 11-7-7.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//
/****************************************
 捕获人脸界面
*****************************************/

#include "UIBase.h"
#include "UILLayout.h"


class ImageButton;


class UICaptureFace :public UILayout
{
    
public:
    
    UICaptureFace();
    
    
    ~UICaptureFace();


	/**初始化*/
	virtual void init();


	///设置已经有多少个用户了
	void setUserCount(unsigned int count);
    
    /**设置是否可见*/
    virtual void  setVisible(bool b);

    
    
protected:
    
    
   
    

protected:

	
	///按钮回调事件
	virtual void buttonHit(Widget* button);



  ///返回到

//	ImageButton* m_pToUserFace;///跳到用户选择按钮

	//ImageButton* m_pGoBackButton;///返回按钮

	Widget* m_pCaptureButton;///拍照按钮


	///当前已经保存了多少个用户
	unsigned int  m_UserCount;


	Widget*       m_pFullWidget;

      




    
};