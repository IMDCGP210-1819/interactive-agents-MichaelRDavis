#pragma once

#include "Gameplay/GameObject/Component.h"

template<class Tx, class Ty>
class TAssetManager;

class SceneNode;

/**
 * 
 */
class SpriteComponent : public Component
{
public:
	SpriteComponent();
	SpriteComponent(int SpriteID, std::string Filename);
	~SpriteComponent();
	
	void Draw();

	void LoadTexture(int SpriteID, std::string FileName);
	void SetTexture(sf::Texture NewTexture);
	void SetPosition(sf::Vector2f NewPosition);

	sf::Texture GetTexture() const { return m_Texture; }
	sf::Sprite GetSprite() const { return m_Sprite; }

	inline std::shared_ptr<TAssetManager<sf::Texture, int>> GetSpriteManager() const
	{
		return m_SpriteManager;
	}

private:
	std::shared_ptr<TAssetManager<sf::Texture, int>> m_SpriteManager;
	std::unique_ptr<SceneNode> m_SpriteNode;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};
