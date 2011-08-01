/**************************************************************
���߹�����������������ߵĴ���������
****************************************************************/


#pragma once 

#include "WarItem.h"

class WarItemManager :public Ogre::Singleton<WarItemManager>
{
public:

	typedef WarItem*  (WarItemManager::*createFun)();
	typedef std::vector<std::pair<WarItemType ,createFun> > CreateFunCollect;

public:

	WarItemManager();


	~WarItemManager(){destroyWarItem();}


	/**����һ������
	*@param itemtype ��������
	*/
	WarItem*  createWarItem(WarItemType  itemtype);


	/**ÿ֡����*/
	void update(float time);


	/**���ٵ���*/
	void destroy(WarItem* pItem);

protected:

	/**�������еĵ���*/
	void destroyWarItem();


	/**���һ����������*/
	bool addItemType(WarItemType itemtype,createFun);

	/**�Ƴ�һ����������*/
	bool removeItemtype(WarItemType itemtype);

	/**���һ����������*/
	createFun  findCrateFun(WarItemType itemtype);


protected:

	/**�����������ߺ���*/
	WarItem* createEggItem();



	


protected:




	WarItemCollect            m_WarItemCollect;///���е��ߵ��б�
	WarItemCollect            m_RemoveItemCollect;

	CreateFunCollect          m_CreateFunCollect;///���������б�



};