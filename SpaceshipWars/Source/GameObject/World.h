#pragma once

class Entity;
class Background;
class NavGrid;
class Spaceship;
class Asteroid;

class World
{
public:
	/**  */
	World(SDL_Renderer* renderer);

	/**  */
	~World();

	/**  */
	void Initialize();

	/**  */
	void Update(float deltaTime);

	/**  */
	void Draw();

#ifdef _DEBUG
	void LogEntityList()
	{
		for (auto entity : m_entityList)
		{
			const std::type_info& entityType = typeid(entity);
			std::cout << entityType.name() << std::endl;
		}
	}
#endif

private:
	/**  */
	SDL_Renderer* m_renderer;

	/**  */
	std::unique_ptr<Background> m_background;

	/**  */
	std::unique_ptr<Spaceship> m_mantis;

	/**  */
	std::unique_ptr<Spaceship> m_scarab;

	/**  */
	std::unique_ptr<Asteroid> m_asteroid;

	/**  */
	std::unique_ptr<NavGrid> m_grid;

	/**  */
	std::vector<Entity*> m_entityList;

	/** Current number of asteroids in the game world. */
	int32_t m_currentAsteroids;

	/** Max number of asteroids in the game world. */
	int32_t m_maxAsteroids;
};