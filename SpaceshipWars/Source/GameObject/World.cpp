#include "stdafx.h"
#include "World.h"
#include "Entity.h"

World::World(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

World::~World()
{

}

void World::Initialize()
{
	for (auto entity : m_entityList)
	{
		entity->Initialize();
	}
}

void World::Update(float deltaTime)
{
	for (auto entity : m_entityList)
	{
		entity->Update(deltaTime);
	}
}

void World::Draw()
{
	for (auto entity : m_entityList)
	{
		entity->Draw(m_renderer);
	}
}
