#include "stdafx.h"
#include "World.h"
#include "Entity.h"
#include "Game/Background.h"
#include "AI/Navigation/NavGrid.h"
#include "Game/Spaceship.h"

World::World(SDL_Renderer* renderer)
{
	m_renderer = renderer;
	m_grid = std::make_unique<NavGrid>();
	m_background = std::make_unique<Background>(m_renderer);
	m_background->CreateTexture("Content/Background.png");
	m_mantis = std::make_unique<Spaceship>();
	m_scarab = std::make_unique<Spaceship>();
}

World::~World()
{

}

void World::Initialize()
{
	for (auto entity : m_entityList)
	{
		entity->Initialize(m_renderer);
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
		entity->Draw();
	}
}
