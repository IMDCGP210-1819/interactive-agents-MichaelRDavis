#include "stdafx.h"
#include "AIApp.h"

AIApp::AIApp()
{
	m_window = nullptr;
	m_appTitle = "Spaceship Wars";
	m_width = 0;
	m_height = 0;
	m_isRunning = true;
}

AIApp::~AIApp()
{
	m_window = nullptr;
}

void AIApp::Startup()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
	}

	SDL_DisplayMode displayMode;
	if (SDL_GetDesktopDisplayMode(0, &displayMode) != 0)
	{
		std::cout << "SDL_GetDisplayMode failed: " << SDL_GetError() << std::endl;
	}

	m_width = displayMode.w;
	m_height = displayMode.h;

	m_window = SDL_CreateWindow(m_appTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);
	if (m_window == nullptr)
	{
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
	}
}

void AIApp::Shutdown()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void AIApp::HandleMessages()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Shutdown();
			m_isRunning = false;
			break;
		}
	}
}
