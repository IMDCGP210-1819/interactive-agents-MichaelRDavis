#include "MiniPCH.h"
#include "Sprite.h"

SpriteComponent::SpriteComponent()
{
	if (!m_Texture.loadFromFile(""))
	{
		// TODO: Log error.
	}

	m_Sprite = sf::Sprite(m_Texture);
}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::SetTexture(sf::Texture NewTexture)
{
	m_Sprite.setTexture(NewTexture);
}

void SpriteComponent::SetPosition(sf::Vector2f NewPosition)
{
	m_Sprite.setPosition(NewPosition);
}

