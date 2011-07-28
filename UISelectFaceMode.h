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

	///��ȡ����mesh��
	bool  getFaceMeshName(Ogre::String& meshName)const ;

	///��ȡͷ��mesh��
	bool  getHeadMeshName(Ogre::String& meshName)const ;

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

	/**���³���ʹ�����������*/
	void updateOrientation();

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

	Ogre::AnimationState* m_pAnimation;



};



////����ѡ������Դ
class UserFaceDataSource
{

public:
	UserFaceDataSource()
	{
		m_FaceModeCollect.push_back("face_shou.mesh");
		m_FaceModeCollect.push_back("face_pang.mesh");

	}


	~UserFaceDataSource()
	{

	}


	unsigned int getFaceModeCount() const{return m_FaceModeCollect.size();}

	const Ogre::String& getFaceMode(unsigned int index	 )const
	{
		assert(index<m_FaceModeCollect.size());
		return m_FaceModeCollect[index];
	}


	
protected:

	Ogre::StringVector m_FaceModeCollect;



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

	//ÿ֡����
	virtual void update(float time);


protected:

	///������������ģ��
	void destroyAllFaceMode();

	///��ʼ�����е�����ģ��
	void initAllFaceMode();


	///��ʼ����
	void initBackEntity();

	///���ٱ���
	void destroyBackEnetiy();


	typedef std::vector<UserSelectMode*>FaceModeCollect;
	FaceModeCollect                   m_FaceModeCollect;

	UserFaceDataSource                m_FaceModeSource;

	Ogre::Entity*                     m_pBackEntity;
	





};