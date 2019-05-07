#pragma once

class Entity;
class Background;
class NavGrid;
class Spaceship;
class Asteroid;

/**
 * World object is container class for all the game objects in the world.
 */
class World
{
public:
	/** Constructor that initializes a renderer object. */
	World(SDL_Renderer* renderer);

	/** Default destructor. */
	~World();

	/** Initialize the world object. */
	void Initialize();

	/** Update the world object, called once per frame. */
	void Update(float deltaTime);

	/** Draw all objects in the game world. */
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
	/** Cached pointer to the renderer object. */
	SDL_Renderer* m_renderer;

	/** The background game object. */
	std::unique_ptr<Background> m_background;

	/** The first spaceship. */
	std::unique_ptr<Spaceship> m_mantis;

	/** The second spaceship. */
	std::unique_ptr<Spaceship> m_scarab;

	/** The list of asteroids in the game world. */
	std::unique_ptr<Asteroid> m_asteroid;

	/** A list of all the entities in the game world. */
	std::vector<Entity*> m_entityList;

	/** Current number of asteroids in the game world. */
	int32_t m_currentAsteroids;

	/** Max number of asteroids in the game world. */
	int32_t m_maxAsteroids;
};