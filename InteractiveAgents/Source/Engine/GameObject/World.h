#pragma once

#include <vector>
#include <SDL.h>
#include <memory>
#include <iostream>
#include <typeinfo>
#include <Box2D/Box2D.h>

class Entity;
class Spaceship;
class EnemySpaceship;
class Asteroid;
class NavGraph;

/**
 * 
 */
class World
{
public:
	/** World constructor - initializes render object */
	World(SDL_Renderer* renderer);

	/** Default World destructor */
	~World();

	/** Update all entities within the game world */
	void UpdateEntities(float deltaTime);

	/** Draw all entities within game world */
	void Draw();

#ifdef _DEBUG
	/** Debug function for logging entities */
	void LogEntityList()
	{
		for (auto entity : m_entities)
		{
			const std::type_info& entityType = typeid(entity);
			std::cout << entityType.name() << std::endl;
		}
	}
#endif

	/** Returns the SDL renderer */
	inline SDL_Renderer* GetRenderer() const
	{
		return m_pRenderer;
	}

	/** Returns the navigation graph */
	inline std::shared_ptr<NavGraph> GetNavGraph() const
	{
		return m_graph;
	}

	/** Returns the physics world object */
	inline b2World* GetPhysicsWorld() const
	{
		return m_worldObject;
	}

private:
	/** Pointer to the SDL renderer */
	SDL_Renderer* m_pRenderer;

	/** Main Box2D world object */
	b2World* m_worldObject;

	/** List of entities within the game world */
	std::vector<Entity*> m_entities;

	/** Navigation graph used by AI */
	std::shared_ptr<NavGraph> m_graph;

	/** Background texture */
	std::unique_ptr<Entity> m_background;

	/** AI controlled Spaceship */
	std::unique_ptr<Spaceship> m_spaceship;

	/** AI controlled enemy spaceship */
	std::unique_ptr<EnemySpaceship> m_enemySpaceship;

	/** Wandering asteroids */
	std::unique_ptr<Asteroid> m_asteroid;

	/** Number of asteroids in game world */
	int32_t m_numAsteroids;
};