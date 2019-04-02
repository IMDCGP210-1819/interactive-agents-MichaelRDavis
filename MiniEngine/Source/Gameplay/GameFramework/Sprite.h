#pragma once

#include "Gameplay/ECS/Entity.h"

namespace Engine
{
	class Sprite : public Entity
	{
	public:
		Sprite();
		~Sprite();

		void SetTexture(sf::Texture NewTexture);
		void SetPosition(sf::Vector2f NewPosition);

		sf::Texture GetTexture() const { return m_Texture; }
		sf::Sprite GetSprite() const { return m_Sprite; }

	private:
		sf::Texture m_Texture;
		sf::Sprite m_Sprite;
	};
}