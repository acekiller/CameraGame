
/***********************************************
ȫ�ֱ����������û�����Ϣ

**************************************************/



#pragma  once



 
class UserInformation
{
public:

	UserInformation()
	{}


	~UserInformation(){}
	
	///�û�ѡ���ģʽ
	void setWarMode(unsigned int mode) {m_SelectWarMode=mode;}

	unsigned int getWarMode()const {return m_SelectWarMode;}


	///�û�ѡ�����������
	void setUserImage(const Ogre::String& imageName){m_SelectUserImage=imageName;}

	const Ogre::String& getUserImage()const {return m_SelectUserImage;}


	///�û�ѡ������ģ��
	void setFaceMode(const Ogre::String&faceMode)   {m_SelectFaceMode=faceMode;}

	const Ogre::String& getFaceMode()const           {return m_SelectFaceMode;}


	///�û�ѡ��ͷ��ģ��
	void setHeadMode(const Ogre::String& headMode)  { m_SelectHeadMode=headMode;}

	const Ogre::String& getHeadMode()const           {return m_SelectHeadMode;}


protected:

	static  unsigned int               m_SelectWarMode;      ///�û�ѡ���ս��ģʽ

	static Ogre::String               m_SelectUserImage;      ///�û�ѡ�����ͼ

	static Ogre::String               m_SelectFaceMode;       ///ѡ�������ģ��

	static Ogre::String               m_SelectHeadMode;       ///ѡ���ͷ��ģ�� 




	

};