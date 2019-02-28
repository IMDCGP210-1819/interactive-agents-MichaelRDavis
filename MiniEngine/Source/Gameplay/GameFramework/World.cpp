#include "MiniPCH.h"
#include "World.h"
#include "Gameplay/ECS/Entity.h"

Engine::World::World()
{

}

Engine::World::~World()
{

}

void Engine::World::Initialize()
{
	for (Entity* Object : m_Entities)
	{
		Object->Initialize();
	}
}

void Engine::World::Update()
{
	for (Entity* Object : m_Entities)
	{
		Object->Update();
	}
}

void Engine::World::Render()
{
	for (Entity* Object : m_Entities)
	{
		Object->Render();
	}
}
