#include "GameApp.h"
#include "GameObject/World.h"
#include <SDL_image.h>
#include <imgui_sdl.h>
#include "Spaceship.h"
#include "SpaceshipFSM.h"

GameApp::GameApp()
{
	m_pWindow = nullptr;
	m_pRenderer = nullptr;
	m_windowWidth = 0;
	m_windowHeight = 0;
	m_isShutdown = false;
	m_uiEnabled = true;
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

	ImGui::CreateContext();
	ImGuiSDL::Initialize(m_pRenderer, m_windowWidth, m_windowHeight);

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
	}

	m_pWorld = std::make_unique<World>(m_pRenderer);
	if (m_pWorld)
	{
		std::cout << "World Created" << std::endl;
	}
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

	ImGuiIO& io = ImGui::GetIO();

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
		{
			SDL_WindowEvent windowEvent = event.window;
			if (windowEvent.type == SDL_WINDOWEVENT_SIZE_CHANGED)
			{
				io.DisplaySize.x = windowEvent.data1;
				io.DisplaySize.y = windowEvent.data2;
			}
		}
		break;

		case SDL_MOUSEWHEEL:
		{
			SDL_MouseWheelEvent wheelEvent = event.wheel;
			m_mouseWheel = wheelEvent.y;
		}
		break;

		case SDL_QUIT:
			m_isShutdown = true;
			Shutdown();
			break;
		}
	}

	GetInput(io, deltaTime);
}

void GameApp::GetInput(ImGuiIO& io, float deltaTime)
{
	const int32_t mouseButtons = SDL_GetMouseState(&m_mousePosX, &m_mousePosY);
	
	io.DeltaTime = deltaTime;
	io.MousePos = ImVec2(m_mousePosX, m_mousePosY);
	io.MouseDown[0] = mouseButtons & SDL_BUTTON_LEFT;
	io.MouseDown[1] = mouseButtons & SDL_BUTTON_RIGHT;
	io.MouseWheel = m_mouseWheel;
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
	ImGui::NewFrame();
	Clear();
	DrawUI();
	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
	m_pWorld->Draw();
	SwapBuffers();
}

void GameApp::DrawUI()
{
	ImGui::Begin("Spaceship Wars");
	ImGui::Text("Spaceship");
	ImGui::Text("Spaceship - Health: %d", m_pWorld->GetSpaceship()->GetHealth());
	ImGui::Text("Spaceship - Ammo: %d", m_pWorld->GetSpaceship()->GetAmmo());

	const std::type_info& spaceshipState = typeid(m_pWorld->GetSpaceship()->GetStateMachine()->GetActiveState());

	ImGui::Text("Spaceship - Current AI State: %s", spaceshipState.name());
	ImGui::Text("Enemy Spaceship");
	ImGui::Text("Enemy Spaceship - Health: %d", m_pWorld->GetEnemySpaceship()->GetHealth());
	ImGui::Text("Enemy Spaceship - Ammo: %d", m_pWorld->GetEnemySpaceship()->GetAmmo());

	const std::type_info& enemySpaceshipState = typeid(m_pWorld->GetEnemySpaceship()->GetStateMachine()->GetActiveState());

	ImGui::Text("Enemy Spaceship - Current AI State: %s", enemySpaceshipState.name());
	ImGui::End();
}
