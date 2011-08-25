
/**************************************************
imageset��������
**************************************************/


#pragma  once

#include "UIIMageSet.h"




class UIImagesetManager :public Ogre::Singleton<UIImagesetManager>
{

public:

	UIImagesetManager();

	~UIImagesetManager();


	/**��ָ�����ļ��д���һ��imageset.
	*@return �ɹ������档ʧ�ܷ��ؼ�
	*@param resourceGroup.ogre����Դ��
	*/
	bool createImageset(const Ogre::String& fileName,const Ogre::String& resourceGroup);



	/**��ȡָ����imageset���޷��ؿ�
	*/
	UIImageSet* getImagesetByName(const Ogre::String& name)const  ;


	/**����ָ�����ֵ�imageset*/
	UIImageSet* getImagesetByFileName(const Ogre::String& name) const;



	/**����ָ��imageset*/
	void  destroyImagetset(const Ogre::String& name);


	/**�������е�imageset*/
	void destroyAllImageset();


	/**ͨ�����ֻ�ȡָ����image����
	@return �޷��ؿ�ָ��
	*/
	Image* getImageByName(const Ogre::String& name)const ;



protected:

	typedef std::vector<UIImageSet*> ImagesetCollect;
	ImagesetCollect   m_ImagesetCollect;




};