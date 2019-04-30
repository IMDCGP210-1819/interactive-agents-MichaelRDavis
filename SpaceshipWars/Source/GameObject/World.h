#pragma once

class Entity;
class Background;

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
	std::vector<Entity*> m_entityList;
};