/**************************************************************
���߹�����������������ߵĴ���������
****************************************************************/


#pragma once 

#include "WarItem.h"

class WarItemManager :public Ogre::Singleton<WarItemManager>
{
public:

	typedef WarItem*  (WarItemManager::*createFun)(const Ogre::String&MeshName,const Ogre::String&textureName);
	typedef std::vector<std::pair<WarItemType ,createFun> > CreateFunCollect;


	///���������
	struct ItemInformat
	{
		WarItemType          m_ItemType;//����id
		Ogre::String         m_MeshName;//ģ������
		Ogre::String         m_Texture;//��ͼ��
		float                m_Power;///������

	};



public:

	WarItemManager();


	~WarItemManager();




	/**����һ������
	*@param itemtype ��������
	*@p
	*/
	WarItem*  createWarItem(WarItemType  itemtype);

	/**��������
	*@param typeName  ������
	*@param  MeshName ����ģ���ļ���.
	*@param  textureName ��ͼ��
	*/
	WarItem*  createWarItem(const Ogre::String& typeName);


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
	//WarItem* createEggItem(const Ogre::String&MeshName,const Ogre::String&textureName);

    /**�ڲ�������������ת���ַ���
	*/
	Ogre::String itemTypeToString(WarItemType itemType);
	
	/**�ڲ��������ַ���ת������
	*/
	WarItemType stringToItemtype(const Ogre::String& itemtype);


	/**��ʼ������������Ϣ*/
	void initItemTypeInformation();


	/**�������Ͳ��ҵ���Ӧ��ģ����*/
	bool  getItemTypeMeshAndTexture(WarItemType itemType,ItemInformat& itemTypeInfor);



protected:




	WarItemCollect            m_WarItemCollect;///���е��ߵ��б�
	WarItemCollect            m_RemoveItemCollect;
	CreateFunCollect          m_CreateFunCollect;///���������б�


	
	
	typedef std::vector<ItemInformat> ItemInformationCollect;
	ItemInformationCollect    m_ItemInformation;



};