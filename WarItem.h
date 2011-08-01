/*******************************************
ģʽ���ĵ�������
*************************************************/


#pragma  once	


class Enemy;


enum WarItemType
{
	WIT_NONE,

	WIT_EGG,//����

};




class WarItem
{

public:
	WarItem(const Ogre::String& name,float power,WarItemType type)
		:m_pTarget(NULL),m_PowerValue(power),m_Type(type)
	{}

	virtual ~WarItem(){}


	///����Ŀ���
	void setTarget(Enemy* pEnemy) {m_pTarget=pEnemy;}

	///��ȡĿ���
	Enemy* getTarget()const       {return m_pTarget;}


	/**��ʼʹ��*/
	virtual void  begin(){}

	/**ÿ֡����,����false��ʾ����ʹ�����*/
	virtual bool  update(float time){return true;}

	/**����*/

	virtual void end(){}

	/**��ȡ��������*/
	float getPower()const {return m_PowerValue;}

	void setPower(float power){m_PowerValue=power;}

	WarItemType getType()      {return m_Type;}

	


protected:

	Enemy*        m_pTarget;///Ŀ���

	float         m_PowerValue;///���к�Ӷ����������

	WarItemType       m_Type;
    
	
};


typedef std::vector<WarItem*> WarItemCollect;



/*************************************************
��������
*****************************************************/
class EggItem :public WarItem
{

public:

	/**���캯��
	*@param startPos ��ʼλ��
	*@pEnemy Ŀ���
	*/
	EggItem(/*const Ogre::Vector3& startPos,Enemy* pEnemy*/);

	virtual ~EggItem();

	/**��ʼʹ��*/
	virtual void  begin();

	/**ÿ֡����*/
	virtual bool   update(float time);

	/**����*/
	virtual void end();

protected:

	////��ʼ��ʵ��
	void initEtity();

	///����ʵ��
	void destroyEntiy();

	/**�ж��Ƿ����Ŀ���*/
	bool hitTarget();




	Ogre::Vector3    m_StartPos;///��ʼλ��

	Ogre::SceneNode* m_pParentNode;///�ڵ�

	Ogre::Entity*    m_pEntity;    ///ģ��ʵ��
	
	Ogre::Vector3    m_pRotateDir;///��ת����


	float            m_liftTime;///��������


}
;