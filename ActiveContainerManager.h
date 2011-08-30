/******************************************
�������������activeContainer��
********************************************/


#pragma once





class ActiveContainer;


typedef std::vector<ActiveContainer*> AcitveContainerVector;

class ActiveContainerManager : public Ogre::Singleton<ActiveContainerManager>
{

public:

	ActiveContainerManager();

	~ActiveContainerManager();


	/**����һ��ActiveContainer
	*������Ѿ����ھͲ��ټ��뷵��false
	*/
	bool  addContainer(ActiveContainer* pContainer);


	/**�Ƴ�һ��activeContainer*/
	bool  removeContainer(ActiveContainer* pContainer);


   /**ÿ֡����*/
	void update(float time);




protected:


	AcitveContainerVector m_AcitveContainerVector;  ///��ǰ�

	AcitveContainerVector m_AddVector;             ///�¼��������
	AcitveContainerVector m_RemoveVector;          ///��Ҫ�Ƴ�������



};