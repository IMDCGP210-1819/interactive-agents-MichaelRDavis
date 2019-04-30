#pragma once

#include "GameObject/Entity.h"

class SpriteComponent;

class Background
{
public:
	Background(SDL_Renderer* renderer);

	~Background();

	void CreateTexture(const std::string& filePath);

	void Draw();

private:
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;

	int32_t m_texWidth;
	int32_t m_texHeight;
};