#include "World.h"
#include "Entity.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "AI/Navigation/Grid.h"

World::World(SDL_Renderer* renderer)
	: m_pRenderer(renderer)
{
	m_numAsteroids = 5;

	m_grid = std::make_shared<Grid>(1920, 1080);

	m_background = std::make_unique<Entity>(this);
	m_background->CreateTexture("Content/Background.png");

	m_spaceship = std::make_unique<Spaceship>(this);
	m_spaceship->CreateTexture("Content/Mantis.png");

	m_asteroid = std::make_unique<Asteroid>(this);
	m_asteroid->CreateTexture("Content/Asteroid.png");

	for (int32_t i = 0; i < m_numAsteroids; i++)
	{
		m_entities.push_back(m_asteroid.get());
	}

	m_entities.push_back(m_background.get());
	m_entities.push_back(m_spaceship.get());

	LogEntityList();
}

World::~World()
{

}

void World::CreateGrid()
{

}

void World::UpdateEntities(float deltaTime)
{
	for (auto entity : m_entities)
	{
		entity->Update(deltaTime);
	}
}

void World::Draw()
{
	for (auto entity : m_entities)
	{
		entity->Draw();
	}
}
