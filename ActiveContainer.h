#pragma  once



#include "Active.h"
#include "ActiveContainerManager.h"

class Active;


class ActiveContainer
{

public:

	ActiveContainer()
		:m_pCurrentActive(NULL)
	{}


	virtual ~ActiveContainer()
	{
		if(m_pCurrentActive!=NULL)
		{
			ActiveContainerManager::getSingleton().removeContainer(this);
			//m_pCurrentActive->end();
			SafeDelete(m_pCurrentActive);
		}
	}

	/**ִ�ж���*/
	void runActive(Active* pActive)
	{
		assert(m_pCurrentActive==NULL);
		assert(pActive);
		m_pCurrentActive=pActive;
		ActiveContainerManager::getSingleton().addContainer(this);

	
	}

	/**����false��ʾ���*/
	bool  updateActive(float time)
	{
		return m_pCurrentActive->update(time);
	}


	void begin()
	{
		m_pCurrentActive->begin();
	}

	void end()
	{
		m_pCurrentActive->end();
		SafeDelete(m_pCurrentActive);
	}

	bool hasActive()const 
	{
		return m_pCurrentActive!=NULL;
	}


protected:

	Active* m_pCurrentActive;


};








