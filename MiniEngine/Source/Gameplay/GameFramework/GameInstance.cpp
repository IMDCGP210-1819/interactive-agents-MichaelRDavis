#include "MiniPCH.h"
#include "GameInstance.h"
#include "Gameplay/GameFramework/World.h"

Engine::GameInstance::GameInstance()
{
	m_World = std::make_unique<World>();
}

Engine::GameInstance::~GameInstance()
{

}
