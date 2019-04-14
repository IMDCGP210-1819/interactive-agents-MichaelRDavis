#include "MiniPCH.h"
#include "GameInstance.h"
#include "Gameplay/GameFramework/World.h"

GameInstance::GameInstance()
{
	m_World = std::make_unique<World>();
}

GameInstance::~GameInstance()
{

}
