
#include "pch.h"
#include "Widget.h"




ImageButton::ImageButton(const Ogre::String& name,const Ogre::String& normalTexture,const Ogre::String& pressTexture)
:m_NormalTexture(normalTexture),m_PressTexture(pressTexture),m_State(BS_UP)
{

	mElement = Ogre::OverlayManager::getSingleton().createOverlayElementFromTemplate("cz/ImageButton", "Panel", name);
	
    /*
    Ogre::TexturePtr pTexture=Ogre::TextureManager::getSingleton().getByName(normalTexture);
    if(pTexture.isNull()==false)
    {
       // pTexture->load();
    }
    
    pTexture=Ogre::TextureManager::getSingleton().getByName(pressTexture);
    if(pTexture.isNull()==false)
    {
       // pTexture->load();
    }
    //*/
    
	m_pMaterial=Ogre::MaterialManager::getSingleton().getByName(name);
	if(m_pMaterial.isNull())
	{
    	m_pMaterial=mElement->getMaterial()->clone(name);
	}
	mElement->setMaterialName(m_pMaterial->getName());

	updateState();

}


ImageButton::~ImageButton()
{

	Ogre::MaterialManager::getSingleton().remove(m_pMaterial->getHandle());


}




void ImageButton::_cursorPressed(const Ogre::Vector2& cursorPos)
{

	if (isCursorOver(mElement, cursorPos, 4))
	{
		m_State=BS_DOWN;
		updateState();
	}


}

void ImageButton:: _cursorReleased(const Ogre::Vector2& cursorPos)
{
	
	m_State=BS_UP;
	updateState();

	if (isCursorOver(mElement, cursorPos, 4))
	{
		if(mListener!=NULL)
		{
			mListener->buttonHit(this);
		}

	}

    

}

void ImageButton::_focusLost()
{

	m_State=BS_UP;
	updateState();

}

void ImageButton::updateState()
{
	if(m_pMaterial.isNull())
	{
		return ;
	}

	if(m_State==BS_UP)
	{

		m_pMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName(m_NormalTexture);
	
	}else
    {
		m_pMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName(m_PressTexture);

	}

}



/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

StaticImage::StaticImage(const Ogre::String& name,const Ogre::String& textureName)
{

	mElement = Ogre::OverlayManager::getSingleton().createOverlayElementFromTemplate("cz/ImageButton", "Panel", name);

	m_pMaterial=Ogre::MaterialManager::getSingleton().getByName(name);
	if(m_pMaterial.isNull())
	{
		m_pMaterial=mElement->getMaterial()->clone(name);
	}

	mElement->setMaterialName(m_pMaterial->getName());
	setImage(textureName);

}


StaticImage::~StaticImage()
{
 
		Ogre::MaterialManager::getSingleton().remove(m_pMaterial->getHandle());

}


void StaticImage::setImage(const Ogre::String& textureName)
{

	if(m_pMaterial.isNull()==false)
	{
		m_pMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName(textureName);
	}


}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////