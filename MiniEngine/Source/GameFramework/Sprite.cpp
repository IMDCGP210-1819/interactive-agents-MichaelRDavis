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

