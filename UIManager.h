//
//  UIManager.h
//  ogreApp
//
//  Created by thcz on 11-7-7.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//

/****************************************************************
 ����ui����
************************************************************/

#pragma once


class UIBase;


typedef std::vector<UIBase*> UICollect;
class UIManager
{
    
public:
    UIManager();
    
    ~UIManager();
    
    
    /**ע��һ��ui,�ɹ������棬ʧ�ܷ��ؼ�*/
    bool registerUI(UIBase* pUI);
    
    
    /**ע��һ��ui,������*/
    bool unregisterUI(UIBase* pUI);
    
    
    /**ͨ�����ֻ�ȡһ��ui,�޷��ؿ�*/
    UIBase* getUIByName(const std::string& name)const ;
    
    
    /**ÿ֡����*/
    void update(float time);
    
    
    /**����һ��ui*/
    void destroyUI(UIBase* pUI);
    
    void destroyUI(const std::string& name);
    
    
    /**�������е�ui*/
    void destroyAllUI();
    
    
    
    ///@{�����¼���

    void TouchBegan(int x,int y);
    
    /**��ָ�뿪*/
	void TouchEnd(int x,int y);
    
	/**��ָ����*/
	void TouchMove(int x,int y);
    
    
    ///@}�����¼�������

    protected:
    
    
    UICollect m_UICollect;

    
    
    
};