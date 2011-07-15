

#pragma  once


#include "UIBase.h"


class ImageButton;
class UISelectUser :public UIBase
{

public:

	UISelectUser();

	~UISelectUser();



	virtual void init();


	/**�����ж��ٸ��û�����*/
	void setUserList(Ogre::StringVectorPtr pUserList);


protected:

	/**ɾ�����е����е��û�ͼ*/
	void destroyAllUserList();


	///��ť�ص��¼�
	virtual void buttonHit(Widget* button);



	///�û��б�
	Ogre::StringVectorPtr m_UserList;


	typedef std::vector<ImageButton*> ImageButtonCollect;
	ImageButtonCollect  m_UserButtonCollect;

	///���ص���������ť
	ImageButton* m_ToCaptureButton;




};