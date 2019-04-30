#include "stdafx.h"
#include "World.h"
#include "Entity.h"
#include "Game/Background.h"

World::World(SDL_Renderer* renderer)
{
	m_renderer = renderer;
	m_background = std::make_unique<Background>(m_renderer);
	m_background->CreateTexture("Content/Background.png");
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
	if (m_background)
	{
		m_background->Draw();
	}

	for (auto entity : m_entityList)
	{
		entity->Draw(m_renderer);
	}
}
