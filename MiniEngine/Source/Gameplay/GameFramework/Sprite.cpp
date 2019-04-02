#include "MiniPCH.h"
#include "Sprite.h"

Engine::Sprite::Sprite()
{
	if (!m_Texture.loadFromFile(""))
	{
		// TODO: Log error.
	}

	m_Sprite = sf::Sprite(m_Texture);
}

Engine::Sprite::~Sprite()
{

}

void Engine::Sprite::SetTexture(sf::Texture NewTexture)
{
	m_Sprite.setTexture(NewTexture);
}

void Engine::Sprite::SetPosition(sf::Vector2f NewPosition)
{
	m_Sprite.setPosition(NewPosition);
}

