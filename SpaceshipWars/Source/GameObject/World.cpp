#include "stdafx.h"
#include "World.h"
#include "Entity.h"
#include "Game/Background.h"
#include "Game/Spaceship.h"
#include "Game/Asteroid.h"

World::World(SDL_Renderer* renderer)
{
	m_maxAsteroids = 5;
	m_currentAsteroids = m_maxAsteroids;

	m_renderer = renderer;

	m_background = std::make_unique<Background>(m_renderer);
	m_background->CreateTexture("Content/Background.png");

	m_mantis = std::make_unique<Spaceship>(m_renderer);
	m_scarab = std::make_unique<Spaceship>(m_renderer);

	m_mantis->CreateTexture("Content/Mantis.png");
	m_scarab->CreateTexture("Content/Scarab.png");

	m_mantis->SetPosition(Vec2(1000.0f, 750.0f));
	m_scarab->SetPosition(Vec2(750.0f, 500.0f));

	m_entityList.push_back(m_mantis.get());
	m_entityList.push_back(m_scarab.get());

	m_asteroid = std::make_unique<Asteroid>(m_renderer);
	m_asteroid->CreateTexture("Content/Asteroid.png");
	for (int32_t i = 0; i < m_maxAsteroids; i++)
	{
		m_entityList.push_back(m_asteroid.get());
		m_asteroid->SetPosition(Vec2(1000.0f + 20.0f, 750.0f + 50.0f));
	}
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
	LogEntityList();
}

void World::Update(float deltaTime)
{
	for (auto entity : m_entityList)
	{
		if (entity->GetIsActive())
		{
			entity->Update(deltaTime);
		}
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