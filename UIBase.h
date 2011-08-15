//
//  UIBase.h
//  ogreApp
//
//  Created by thcz on 11-7-6.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//


#pragma once
#include "SdkTrays.h"


class Widget;

typedef std::vector<Widget*> WidgetCollect;



/**
 ��Ϸ�ģգɽ���Ļ��࣬һ��ʵ����ʾһ����Ϸҳ��
*/

class UIBase :public SdkTrayListener
{
public:

	enum Flag
	{
		F_SHOW=1<<1,//��Ҫ��ʾ
		F_HIDE=1<<2,//��Ҫ����
	};

    
public:
    
    /** ���캯����
       *@param name uibase����
       *@param templateName overlayģ�������
      */
    UIBase(const std::string& name, const std::string& templateName);
    
    
    virtual ~UIBase();
    
    
    /**��ȡ����*/
    const std::string& getName()const {return m_Name;}
    
    /**��ʼ��*/
    virtual void init();
    
    /**ÿ֡������*/
    virtual void update(float time);
    
    
    /**��ʼ����,*/
    virtual void onBeginTouch(int x,int y);
    
    
    /**������ָ*/
    virtual void onMoveTouch(int x,int y);
    
    
    /**��ָ�뿪*/
    virtual void onEndTouch(int x,int y);
    
    
    
    /**�����Ƿ�ɼ�*/
    virtual void  setVisible(bool b);
    
    
    /**�ж��Ƿ�ɼ�,�����ͬ������Ӧ��ָ�¼�*/
    virtual bool   isVisible()const ;
    

    /**����һ��overlayElement�����Ӷ���*/
    static bool destroyOverlayElementAndChild(Ogre::OverlayElement* pOverlay);
    
     /**����һ��overlay�����Ӷ���*/
    static bool destroyOverlayAndChiled(Ogre::Overlay* pOverlay);
    
    
    /**���ý����z*/
    void setZorder(unsigned short z);
    
    
    /**��ȡ����z,�������δ��ʼ����0*/
    unsigned short getZorder()const;


	/**����һ���ؼ�*/
	bool registerWidget(Widget* pWidget);

	/**
	*/
	bool unregisterWidget(Widget* pWidget);


	/**�������ֻ�ȡ�ؼ�*/
	Widget* getWidgetByName(const Ogre::String& anem);


	/**��������*/
	void    setFlag(Flag flag){m_Flag=flag;}
	void    addFlag(Flag roleFlag){m_Flag|=roleFlag;}
	void    removeFlag(Flag roleFlag){m_Flag&=~roleFlag;}
	unsigned int  getFlag()const {return m_Flag;}
	bool    hasFlag(Flag flag) const   {return (m_Flag&flag)!=0;}

    
    
protected:
    
    /**����
       ����overlay�����Ӷ���
     */
    void destroy();


	/**�������еĿؼ�*/
	void destroyAllWidget();


	/**����һ���ؼ�*/
	void destroyWidget(Widget* pWidget);






    
    std::string m_Name;//// �գ���
    
    std::string m_TemplateName;/// ģ����
    
    Ogre::Overlay* m_pParentOverlay; ///���ϲ�overlay
    
	WidgetCollect m_WidgetCollect;    ///�ӿؼ��б�

	unsigned int  m_Flag;             ///��ǣ������������
    
    
    
    
    
};