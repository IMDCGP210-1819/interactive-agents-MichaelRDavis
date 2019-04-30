#include "stdafx.h"
#include "Background.h"

Background::Background(SDL_Renderer* renderer)
	: m_renderer(renderer)
{
	m_texWidth = 0;
	m_texHeight = 0;
}

Background::~Background()
{

}

void Background::CreateTexture(const std::string& filePath)
{
	SDL_Surface* surface = IMG_Load(filePath.c_str());
	if (surface == nullptr)
	{
		std::cout << "Unable to load a texture file " << filePath.c_str() << std::endl;
	}

	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_FreeSurface(surface);
	if (m_texture == nullptr)
	{
		std::cout << "Failed to create texture for " << filePath.c_str() << std::endl;
	}
}

void Background::Draw()
{
	if (m_texture)
	{
		SDL_Rect rect;
		rect.w = m_texWidth;
		rect.h = m_texHeight;
		rect.x = rect.w / 2;
		rect.y = rect.h / 2;

		SDL_RenderCopyEx(
			m_renderer,
			m_texture,
			nullptr,
			&rect,
			0.0f,
			nullptr,
			SDL_FLIP_NONE);
	}
}
