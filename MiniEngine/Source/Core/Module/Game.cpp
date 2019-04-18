#include "MiniPCH.h"
#include "Game.h"
#include "Gameplay/World/World.h"

Game::Game()
{
	m_World = std::make_shared<World>();
}

Game::~Game()
{

}
