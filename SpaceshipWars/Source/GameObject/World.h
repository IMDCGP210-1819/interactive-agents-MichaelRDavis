#pragma once

class Entity;
class Background;
class NavGrid;
class Spaceship;

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
	std::unique_ptr<NavGrid> m_grid;

	/**  */
	std::vector<Entity*> m_entityList;
};