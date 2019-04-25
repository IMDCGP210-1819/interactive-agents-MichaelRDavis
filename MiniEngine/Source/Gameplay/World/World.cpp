#include "MiniPCH.h"
#include "World.h"
#include "Gameplay/GameObject/Entity.h"

World::World()
{
	Init();
}

World::~World()
{

}

void World::Init()
{
	for (auto GameObject : m_EntityList)
	{
		GameObject->Initialize();
	}
}

void World::Update(float DeltaTime)
{
	for (auto GameObject : m_EntityList)
	{
		GameObject->Update(DeltaTime);
	}
}

void World::Draw(SDL_Renderer* Renderer)
{
	for (auto GameObject : m_EntityList)
	{
		GameObject->Draw(Renderer);
	}
}

void World::AttachEntity(Entity* GameObject)
{
	m_EntityList.push_back(GameObject);
}
