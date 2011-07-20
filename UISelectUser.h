

#pragma  once


#include "UIBase.h"


class ImageButton;
class TimeImageButton;
class UISelectUser :public UIBase
{

public:

	UISelectUser();

	~UISelectUser();



	virtual void init();


	/**�����ж��ٸ��û�����*/
	void setUserList(Ogre::StringVectorPtr pUserList);


	///ÿ֡����
	 virtual void update(float time);

protected:

	/**��ָ�뿪*/
	virtual void onEndTouch(int x,int y);

	///�������������б�
	void updateUserList();


	/**ɾ�����е����е��û�ͼ*/
	void destroyAllUserList();


	///��ť�ص��¼�
	virtual void buttonHit(Widget* button);

	/**�������е���Ƭ��ť״̬*/
	void   resetUserFaceButton();



	///�û��б�
	Ogre::StringVectorPtr m_UserList;


	typedef std::vector<TimeImageButton*> ImageButtonCollect;
	ImageButtonCollect  m_UserButtonCollect;

	///���ص���������ť
	ImageButton* m_ToCaptureButton;

	bool         m_NeedUpdate;///�Ƿ�ˢ��



};