#include "MiniPCH.h"
#include "GameInstance.h"
#include "Gameplay/GameFramework/World.h"

Game::Game()
{
	m_World = std::make_unique<World>();
}

Game::~Game()
{

}
