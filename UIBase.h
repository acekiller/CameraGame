//
//  UIBase.h
//  ogreApp
//
//  Created by thcz on 11-7-6.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//


#pragma once



/**
 ��Ϸ�ģգɽ���Ļ��࣬һ��ʵ����ʾһ����Ϸҳ��
*/

class UIBase
{
    
    
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
    virtual void update(float time){};
    
    
    /**��ʼ����*/
    virtual void onBeginTouch(){};
    
    
    /**������ָ*/
    virtual void onMoveTouch(){};
    
    
    /**��ָ�뿪*/
    virtual void onEndTouch(){};
    
    
    
    /**�����Ƿ�ɼ�*/
    void  setVisible(bool b);
    
    
    /**�ж��Ƿ�ɼ�,�����ͬ������Ӧ��ָ�¼�*/
    bool   isVisible()const ;
    

    /**����һ��overlayElement�����Ӷ���*/
    static bool destroyOverlayElementAndChild(Ogre::OverlayElement* pOverlay);
    
     /**����һ��overlay�����Ӷ���*/
    static bool destroyOverlayAndChiled(Ogre::Overlay* pOverlay);
    
    
    /**���ý����z*/
    void setZorder(unsigned short z);
    
    
    /**��ȡ����z,�������δ��ʼ����0*/
    unsigned short getZorder()const;
    
    
protected:
    
    /**����
       ����overlay�����Ӷ���
     */
    void destroy();
    
    std::string m_Name;//// �գ���
    
    std::string m_TemplateName;/// ģ����
    
    Ogre::Overlay* m_pParentOverlay; ///���ϲ�overlay
    
    
    
    
    
    
    
};