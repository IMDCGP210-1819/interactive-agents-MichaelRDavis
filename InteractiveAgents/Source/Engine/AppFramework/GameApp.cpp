#include "GameApp.h"
#include "GameObject/World.h"
#include <SDL_image.h>

GameApp::GameApp()
{
	m_pWindow = nullptr;
	m_pRenderer = nullptr;
	m_windowWidth = 0;
	m_windowHeight = 0;
	m_isShutdown = false;
}

GameApp::~GameApp()
{
	Shutdown();
}

void GameApp::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	}

	SDL_DisplayMode displayMode;

	for(int32_t i = 0; i < SDL_GetNumVideoDisplays(); i++)
	{
		int32_t displayCount = SDL_GetCurrentDisplayMode(i, &displayMode);
		if(displayCount != 0)
		{
			SDL_Log("Could not get display mode for video display %d: %s", i, SDL_GetError());
		}

		m_windowWidth = displayMode.w;
		m_windowHeight = displayMode.h;
	}

	uint32_t windowFlags = SDL_WINDOW_ALLOW_HIGHDPI;
	m_pWindow = SDL_CreateWindow("Interactive Agents", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowWidth, m_windowHeight, windowFlags);
	if (m_pWindow == nullptr)
	{
		SDL_Log("Could not create window: %s", SDL_GetError());
	}

	SDL_SetWindowBordered(m_pWindow, SDL_TRUE);
	SDL_MaximizeWindow(m_pWindow);

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
	if (m_pRenderer == nullptr)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
	}

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
	}

	m_pWorld = std::make_unique<World>(m_pRenderer);
}

void GameApp::Shutdown()
{
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

void GameApp::Update(float deltaTime)
{
	m_pWorld->UpdateEntities(deltaTime);
	Draw();

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_isShutdown = true;
			Shutdown();
			break;
		}
	}
}

void GameApp::Clear()
{
	SDL_RenderClear(m_pRenderer);
}

void GameApp::SwapBuffers()
{
	SDL_RenderPresent(m_pRenderer);
}

void GameApp::Draw()
{
	Clear();
	m_pWorld->Draw();
	SwapBuffers();
}
