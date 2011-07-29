/*******************************************
ģʽ���ĵ�������
*************************************************/


class Enemy;

class Item
{

public:
	Item(const Ogre::String& name)
		:m_pTarget(NULL)
	{}

	virtual ~Item(){}


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

	


protected:

	Enemy*        m_pTarget;///Ŀ���
    
	
};




/*************************************************
��������
*****************************************************/
class EggItem :public Item
{

public:

	/**���캯��
	*@param startPos ��ʼλ��
	*@pEnemy Ŀ���
	*/
	EggItem(const Ogre::Vector3& startPos,Enemy* pEnemy);

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