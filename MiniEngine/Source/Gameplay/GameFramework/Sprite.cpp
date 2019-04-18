#include "MiniPCH.h"
#include "Sprite.h"
#include "Resource/ResourceManager.h"

SpriteComponent::SpriteComponent()
{
	m_SpriteManager = new TAssetManager<sf::Texture, int>();
}

SpriteComponent::SpriteComponent(int SpriteID, std::string Filename)
{
	m_SpriteManager = new TAssetManager<sf::Texture, int>();
	m_SpriteManager->Load(SpriteID, Filename);
	m_Texture = m_SpriteManager->Get(SpriteID);
	m_Sprite = sf::Sprite(m_Texture);
}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::Draw(sf::RenderWindow* Window)
{
	Window->draw(m_Sprite);
}

void SpriteComponent::SetTexture(sf::Texture NewTexture)
{
	m_Sprite.setTexture(NewTexture);
}

void SpriteComponent::SetPosition(sf::Vector2f NewPosition)
{
	m_Sprite.setPosition(NewPosition);
}

