#include "MiniPCH.h"
#include "Window.h"

Window::Window()
{
	InitializeWindow();
}

Window::~Window()
{
	DestroyWindow();
}

void Window::InitializeWindow()
{ 
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_DisplayMode DisplayMode;
	if (SDL_GetDesktopDisplayMode(0, &DisplayMode) != 0)
	{

	}

	m_Width = DisplayMode.w;
	m_Height = DisplayMode.h;

	m_Window = SDL_CreateWindow("Spaceship Wars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_SHOWN);
	if (m_Window == nullptr)
	{
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
	}
}

void Window::DestroyWindow()
{
	SDL_DestroyWindow(m_Window);
}

