#pragma once

#include "Gameplay/GameObject/Component.h"

template<class Tx, class Ty>
class TAssetManager;

class SpriteComponent : public Component
{
public:
	SpriteComponent();
	SpriteComponent(int SpriteID, std::string Filename);
	~SpriteComponent();
	
	void Draw(sf::RenderWindow* Window);

	void SetTexture(sf::Texture NewTexture);
	void SetPosition(sf::Vector2f NewPosition);

	sf::Texture GetTexture() const { return m_Texture; }
	sf::Sprite GetSprite() const { return m_Sprite; }

	inline TAssetManager<sf::Texture, int>* GetSpriteManager() const
	{
		return m_SpriteManager;
	}

private:
	TAssetManager<sf::Texture, int>* m_SpriteManager;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};
