/********************************************


**********************************************/


#pragma  once


class UIImageSet;

class Image
{

	friend class UIImageSet;
protected:

	/**���캯��
	*@param name
	*@UIImageSet ������imagesetָ��
	*@left ,top,right,bottom image������imageset������λ�á�0---1֮��
	*/
	Image(const Ogre::String& name,UIImageSet* pParent,float left,float top,float right,float bottom)
		:m_Name(name),m_pParent(pParent),m_UV(left,top,right,bottom)
	{

	}


	~Image(){}

public:
	const Ogre::String& getName()const {return m_Name;}


	const Ogre::Vector4& getUV()const {return m_UV;}


	UIImageSet*          getParent()const {return m_pParent;}


protected:

	Ogre::String    m_Name;///����
	UIImageSet*     m_pParent;
	Ogre::Vector4   m_UV;  ///ÿ�����uv


};


typedef std::vector<Image*> UIImageCollect;