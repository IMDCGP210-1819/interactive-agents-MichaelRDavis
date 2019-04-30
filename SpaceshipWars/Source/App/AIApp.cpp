#include "stdafx.h"
#include "AIApp.h"
#include "GameObject/World.h"

AIApp::AIApp()
{
	m_window = nullptr;
	m_renderer = nullptr;
	m_appTitle = "Spaceship Wars";
	m_width = 0;
	m_height = 0;
	m_isRunning = true;
}

AIApp::~AIApp()
{
	m_window = nullptr;
	m_renderer = nullptr;
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

	SDL_SetWindowBordered(m_window, SDL_TRUE);
	SDL_MaximizeWindow(m_window);

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr)
	{
		std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
	}

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		std::cout << "Unable to initialize SDL_image: " << SDL_GetError() << std::endl;
	}

	m_world = std::make_unique<World>(m_renderer);
	if (m_world)
	{
		m_world->Initialize();
	}
}

void AIApp::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void AIApp::Update()
{
	float deltaTime = SDL_GetTicks();

	HandleMessages();
	m_world->Update(deltaTime);
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

void AIApp::Render()
{
	Clear();
	m_world->Draw();
	SwapBuffers();
}

void AIApp::Clear()
{
	SDL_RenderClear(m_renderer);
}

void AIApp::SwapBuffers()
{
	SDL_RenderPresent(m_renderer);
}
