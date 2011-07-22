/**************************************************
ѡ���û��������ͽ��档�������ʵ����3d����,ѡ����������ģ��
**************************************************/



#include "UIBase.h"



///�û�ѡ������ͷ����
class UserSelectMode
{
public:

	/**���캯�� 
	*@param faceMesh ����mesh�ļ���
	*@param ͷ�׵��ļ���
	*/
	UserSelectMode(const Ogre::String& faceMesh,const Ogre::String&headMesh);

	~UserSelectMode();

	///ÿ֡����
	void update(float time);

	/**��������ģ��*/
	void setFaceMesh(const Ogre::String& faceMesh);

	/**����ͷ��ģ��*/
	void setHeadMesh(const Ogre::String& headMesh);


	///�Ƿ��������ཻ��������ʰȡ
	bool isIntersect(const  Ogre::Ray& ray); 


	/**����*/
	void reset();


	///�ƶ���ָ��λ��
	void translate(const Ogre::Vector3& pos);


	/**�����Ƿ�ɼ�*/
	void setVisible(bool b);


	/**����λ��*/
	void setPosition(float x,float y,float z);

protected:

	
	/**����λ��
	*@param precent 0--1.0֮��
	*/
	void updatePos(float precent);


	Ogre::Vector3  m_orginPos;///ԭʼλ��

	Ogre::Vector3  m_targetPos;//Ŀ��λ��

	float          m_currentTime;///�ƶ�ʱ��
	bool           m_isRoll;     ///�Ƿ��ƶ�

	Ogre::SceneNode* m_pNode;    
	Ogre::Entity*    m_pFaceEntity;
	Ogre::Entity*    m_pHeadEntity;



};






class UISelectFaceMode :public UIBase
{


public:


	
	UISelectFaceMode();


	~UISelectFaceMode();




protected:

	void init();


	/**�����Ƿ�ɼ�*/
	virtual void  setVisible(bool b);


	///�����û�ѡ��ģ�� �Ƿ���� 
	void setUserSelctModeVisible(bool b);


	/**��ָ�뿪*/
	virtual void onEndTouch(int x,int y);


protected:

	///������������ģ��
	void destroyAllFaceMode();


	typedef std::vector<UserSelectMode*>FaceModeCollect;
	FaceModeCollect          m_FaceModeCollect;


	





};