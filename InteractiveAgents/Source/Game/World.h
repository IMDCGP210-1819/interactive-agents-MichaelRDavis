#pragma once

#include <vector>
#include <SDL.h>
#include <memory>
#include <iostream>
#include <typeinfo>

class Entity;
class Spaceship;
class Asteroid;

class World
{
public:
	World(SDL_Renderer* renderer);
	~World();

	void CreateGrid();

	void UpdateEntities(float deltaTime);
	void Draw();

#ifdef _DEBUG
	void LogEntityList()
	{
		for (auto entity : m_entities)
		{
			const std::type_info& entityType = typeid(entity);
			std::cout << entityType.name() << std::endl;
		}
	}
#endif

	inline SDL_Renderer* GetRenderer() const
	{
		return m_pRenderer;
	}

private:
	SDL_Renderer* m_pRenderer;

	std::vector<Entity*> m_entities;
	std::unique_ptr<Entity> m_background;
	std::unique_ptr<Spaceship> m_spaceship;
	std::unique_ptr<Asteroid> m_asteroid;

	int32_t m_numAsteroids;
};