//
//  UIManager.cpp
//  ogreApp
//
//  Created by thcz on 11-7-7.
//  Copyright 2011�� __MyCompanyName__. All rights reserved.
//
#include "pch.h"
#include "UIManager.h"
#include "UIBase.h" 


//-----------------------------------------------------------------------
UIManager::UIManager()
{
    
}

//-----------------------------------------------------------------------
UIManager::~UIManager()
{
    destroyAll();
}


//-----------------------------------------------------------------------
bool UIManager::registerUI(UIBase* pUI)
{
    if(pUI==NULL)
        return false;
    
    
    ///���û��ע������Լ������
    if (getUIByName(pUI->getName())!=NULL)
    {
       // m_UICollect.push_back(pUI);
        return true;
    }
    
    return false;
    
}


//-----------------------------------------------------------------------
bool  UIManager::unregisterUI(UIBase* pUI)
{
	return true;
    
}


//-----------------------------------------------------------------------
UIBase* UIManager::getUIByName(const std::string& name)
{
    return NULL;
}


//-----------------------------------------------------------------------
void UIManager::update(float time)
{
    
}


//-----------------------------------------------------------------------
void UIManager::destroyUI(UIBase* pUI)
{
    
}


//-----------------------------------------------------------------------
void UIManager::destroyUI(const std::string& name)
{
    
}


//-----------------------------------------------------------------------
void UIManager::destroyAll()
{
    
}
