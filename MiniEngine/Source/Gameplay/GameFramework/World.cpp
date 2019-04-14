#include "MiniPCH.h"
#include "World.h"
#include "Gameplay/ECS/Entity.h"

World::World()
{

}

World::~World()
{

}

void World::Initialize()
{
	for (Entity* Object : m_Entities)
	{
		Object->Initialize();
	}
}

void World::Update(float DeltaTime)
{
	for (Entity* Object : m_Entities)
	{
		Object->Update(DeltaTime);
	}
}

void World::Render()
{
	for (Entity* Object : m_Entities)
	{
		Object->Render();
	}
}
