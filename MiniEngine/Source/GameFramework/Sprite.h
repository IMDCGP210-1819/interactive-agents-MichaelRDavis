#pragma once

#include "GameFramework/Entity.h"

namespace Engine
{
	class Sprite : public Entity
	{
	public:
		Sprite();
		~Sprite();

		sf::Texture GetTexture() const { return m_Texture; }
		sf::Sprite GetSprite() const { return m_Sprite; }

	private:
		sf::Texture m_Texture;
		sf::Sprite m_Sprite;
	};
}