#include "MiniPCH.h"
#include "Game.h"
#include "Gameplay/World/World.h"

Game::Game()
	: Engine()
{
	m_World = std::make_shared<World>();
}

Game::~Game()
{

}

void Game::Update()
{
	Engine::Update();
}
