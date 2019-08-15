#include "World.h"
#include "Entity.h"
#include "Spaceship.h"
#include "EnemySpaceship.h"
#include "Asteroid.h"
#include "AI/Navigation/NavGraph.h"
#include "Rendering/Drawing.h"

World::World(SDL_Renderer* renderer)
	: m_pRenderer(renderer)
{
	m_numAsteroids = 5;

	m_graph = std::make_unique<NavGraph>(this);
	m_graph->BuildGraph();

	m_background = std::make_unique<Entity>(this);
	m_background->CreateTexture("Content/Background.png");

	m_spaceship = std::make_unique<Spaceship>(this);
	m_spaceship->CreateTexture("Content/Mantis.png");
	m_spaceship->SetPosition(Vector2f(100.0f, 100.0f));

	m_enemySpaceship = std::make_unique<EnemySpaceship>(this);
	m_enemySpaceship->CreateTexture("Content/Scarab.png");
	m_enemySpaceship->SetPosition(Vector2f(250.0f, 250.0f));

	m_asteroid = std::make_unique<Asteroid>(this);
	m_asteroid->CreateTexture("Content/Asteroid.png");

	for (int32_t i = 0; i < m_numAsteroids; i++)
	{
		m_entities.push_back(m_asteroid.get());
	}

	m_entities.push_back(m_background.get());
	m_entities.push_back(m_spaceship.get());
	m_entities.push_back(m_enemySpaceship.get());

	LogEntityList();
}

World::~World()
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
		m_graph->DrawGraph();
	}
}
