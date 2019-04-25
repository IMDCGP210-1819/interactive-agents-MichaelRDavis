#include "MiniPCH.h"
#include "Game.h"
#include "Gameplay/World/World.h"
#include "Rendering/Renderer.h"

Game::Game()
	: Engine()
{
	m_World = std::make_shared<World>();
}

Game::~Game()
{

}

void Game::Initialize()
{
	m_World->Init();
}

void Game::Update(float DeltaTime)
{
	Engine::Update(DeltaTime);

	m_World->Update(DeltaTime);
}

void Game::Draw()
{
	m_World->Draw(m_Renderer->GetSDLRenderer());
}
