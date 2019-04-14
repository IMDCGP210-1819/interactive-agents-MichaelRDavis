#include "MiniPCH.h"
#include "Sprite.h"

Sprite::Sprite()
{
	if (!m_Texture.loadFromFile(""))
	{
		// TODO: Log error.
	}

	m_Sprite = sf::Sprite(m_Texture);
}

Sprite::~Sprite()
{

}

void Sprite::SetTexture(sf::Texture NewTexture)
{
	m_Sprite.setTexture(NewTexture);
}

void Sprite::SetPosition(sf::Vector2f NewPosition)
{
	m_Sprite.setPosition(NewPosition);
}

