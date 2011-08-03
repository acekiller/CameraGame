/*******************************************
ģʽ���ĵ�������
*************************************************/


#pragma  once	


class Enemy;
class WarItem;

enum WarItemType
{
	WIT_NONE,
	WIT_EGG,//����
	WIT_BRICK, //��ש
	WIT_SHOE,//Ь��
	WIT_BENCH,//���
	WIT_STICK,//����
	WIT_KNIFE,//�˵�
	
};


class WarItemListen
{
public:
	WarItemListen(){}

	virtual ~WarItemListen(){}
 	virtual void onHitTarget(WarItem* pItem,Enemy* pEnemy)=0;
};



class WarItem
{

public:
	WarItem(WarItemType type,float power)
		:m_pTarget(NULL),m_PowerValue(power),m_Type(type),m_pListen(NULL)
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

	
	/**���ü���*/
	void setListen(WarItemListen* pListen){m_pListen=pListen;}


	/**�㲥�������Ŀ��*/
	 void fireHitTarget()
	 {
		 if(m_pListen!=NULL)
		 {
			 m_pListen->onHitTarget(this,m_pTarget);
		 }
	 }


protected:

	Enemy*        m_pTarget;///Ŀ���

	float         m_PowerValue;///���к�Ӷ����������

	WarItemType       m_Type;

	WarItemListen*    m_pListen; ///����
    
	
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
	EggItem(const Ogre::String&MeshName,const Ogre::String&textureName,float Power);

	virtual ~EggItem();

	/**��ʼʹ��*/
	virtual void  begin();

	/**ÿ֡����*/
	virtual bool   update(float time);

	/**����*/
	virtual void end();

protected:

	////��ʼ��ʵ��
	void initEntity(const Ogre::String& entityName);

	///����ʵ��
	void destroyEntiy();

	/**�ж��Ƿ����Ŀ���*/
	bool hitTarget();




	Ogre::Vector3    m_StartPos;///��ʼλ��

	Ogre::SceneNode* m_pParentNode;///�ڵ�

	Ogre::Entity*    m_pEntity;    ///ģ��ʵ��
	
	Ogre::Vector3    m_pRotateDir;///��ת����

	float            m_liftTime;///��������

	Ogre::String     m_TextreuName;

}
;