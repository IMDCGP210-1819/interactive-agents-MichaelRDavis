#pragma once

#include "Gameplay/GameObject/Component.h"

/**
 * 
 */
class SpriteComponent : public Component
{
public:
	SpriteComponent();
	~SpriteComponent();

	void Draw(SDL_Renderer* Renderer);

	void SetTexture(SDL_Texture* NewTexture);

	inline SDL_Texture* GetTexture() const
	{
		return m_Texture;
	}

	inline int32_t GetSpriteHeight() const
	{
		return m_SpriteHeight;
	}

	inline int32_t GetSpriteWidth() const
	{
		return m_SpriteWidth;
	}

private:
	SDL_Texture* m_Texture;
	int32_t m_SpriteWidth;
	int32_t m_SpriteHeight;
};
