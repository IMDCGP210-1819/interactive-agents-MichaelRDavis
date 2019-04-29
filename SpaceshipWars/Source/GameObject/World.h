#pragma once

class Entity;

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
	std::vector<Entity*> m_entityList;
};