#include "MiniPCH.h"
#include "Renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::Init(SDL_Window* Window)
{
	m_Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
}

void Renderer::SwapBuffers()
{
	SDL_RenderPresent(m_Renderer);
}

void Renderer::ClearBuffer()
{
	SDL_RenderClear(m_Renderer);
}
