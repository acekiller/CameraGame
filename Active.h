

/***********************************************
������
****************************************************/

#pragma  once 

/**����������*/
class ActiveListen
{
public:

	virtual void onBegin(){}

	virtual void onEnd(){}



};







class Active
{

public:

	Active()
		:m_pListen(NULL){}

	virtual ~Active(){}

	/**��ʼ����*/
	virtual void  begin()
	{
		if(m_pListen!=NULL)
		{
			m_pListen->onBegin();
		}
	}

	 /**ÿ֡����,����false��ʾ���*/
	virtual bool   update(float time){ return true;}

	/**��������*/
	virtual void  end()
	{
		if(m_pListen!=NULL)
		{
			m_pListen->onEnd();
		}
	}

	void  setListen(ActiveListen* pListen)
	{
		m_pListen=pListen;
	}

protected:
	

	ActiveListen*      m_pListen;


};
typedef  std::vector<Active*> ActitveVector;




/**�������У��Ѷ����������һ�����������������еĶ�������
���У�ֱ�����ж���������ˣ��������������н���*/

class ActiveQueue :public Active
{
public:

	ActiveQueue(){}

    virtual 	~ActiveQueue();

	/**����������һ������*/
	void         addActive(Active* pActive);


	/**��ʼ����*/
	virtual void  begin();

    /**ÿ֡����*/
	virtual bool   update(float time);

	/**��������*/
	virtual void  end();

	
protected:

	/**ɾ�����ж���*/
	void  destroyAllActive();


	ActitveVector           m_ActiveVector;   ///�����б�

	ActitveVector::iterator m_CurrentIterator;//��ǰ��Ķ���

};







/********************************************************
�ӵ�ǰ������ת���ٶ�
***********************************************************/
class RotateActive :public Active
{
public:
	/**���캯��
	*@param axis ��ת��
	*@param radian ��Ҫ��ת���ٻ���
	*@param time   ��ɵ�ʱ��
	*/
	RotateActive(Ogre::Node* pNode,const Ogre::Vector3& axis,Ogre::Radian radian,float time);


	~RotateActive();


	/**��ʼ����*/
	virtual void  begin();

	/**ÿ֡����*/
	virtual bool   update(float time);

	/**��������*/
	virtual void  end();

protected:

	Ogre::Node*            m_pNode;    ///�ڵ�
	Ogre::Vector3          m_Axis;       ///��ת��
	Ogre::Radian           m_radian;     //��ת����
	float                  m_leftTime;///���ʱ��
	float                  m_currentTime;//��ʱǰ���ʱ��
	Ogre::Quaternion       m_orginQuaternion;///��ʼ�ĳ���


};





/**********************************************************
///�ӵ�ǰ������ת���ĸ�����
***********************************************************/
class RotateToActive :public Active
{
public:

	/**���캯��
	*@param pTarget ��Ҫת���Ľ�ڵ�
	*@param quat    ת����Ŀ�곯��
	*@param time    �����Ҫ����ʱ��
	*/
	RotateToActive(Ogre::SceneNode* pTarget,const Ogre::Quaternion& quat,float time);


	~RotateToActive();


	/**��ʼ����*/
	virtual void  begin();

	/**ÿ֡����*/
	virtual bool   update(float time);

	/**��������*/
	virtual void  end();



protected:

	Ogre::SceneNode*           m_pTarget;              ///��תĿ��
	Ogre::Quaternion           m_pTargetQuater;        ///Ŀ�곯��
	Ogre::Quaternion           m_OrignQuater;          ///��ǰ����
	float                      m_LeftTime;             ///�����ʱ��
	float                      m_CurrentTime;          ///��ǰʱ��


};



/***************************************************************
�ӵ�ǰ��λ����ָ���ķ����ƶ�ָ���ľ���
****************************************************************/

class MoveActive :public Active
{
public:

	/**���캯��
	*@param pNode ��Ҫλ�ƵĽڵ�
	*@param dir   �ƶ��ķ���
	*@param  space  �ƶ����������
	*@param  lenght  �ƶ���Զ
	*@param  time    �ƶ�����ʱ��
	*/
	MoveActive(Ogre::Node* pNode,const Ogre::Vector3& dir,Ogre::Node::TransformSpace Space ,float length,float time);



	~MoveActive();


	/**��ʼ����*/
	virtual void  begin();

	/**ÿ֡����*/
	virtual bool   update(float time);

	/**��������*/
	virtual void  end();



protected:

	Ogre::Node*                  m_pNode;
	Ogre::Vector3                m_Dir;
	Ogre::Node::TransformSpace   m_Space;
	float                             m_length;
	float                             m_lefttime;
	float                             m_currentTime;
	Ogre::Vector3                     m_OrginPos;



};




/******************************************************************
�ӵ�ǰλ��λ�Ƶ�ָ����Ŀ���
*****************************************************************/
class MoveToActive :public Active
{

public:

	MoveToActive(Ogre::SceneNode* pTarget,const Ogre::Vector3& TargetPosition,float time );

	~MoveToActive(){}

	/**��ʼ����*/
	virtual void  begin();

	/**ÿ֡����*/
	virtual bool   update(float time);

	/**��������*/
	virtual void  end();



protected:

	Ogre::SceneNode*           m_pTarget;              ///��תĿ��
	Ogre::Vector3              m_TargetPosition;        ///Ŀ�곯��
	Ogre::Vector3              m_OrignPosition;          ///��ǰ����
	float                      m_LeftTime;             ///�����ʱ��
	float                      m_CurrentTime;          ///��ǰʱ��

};