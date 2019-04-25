#pragma once

class Entity;

class World
{
public:
	/** Default constructor. */
	World();

	/** Default destructor. */
	~World();

	/**  */
	void Init();

	/**  */
	void Update(float DeltaTime);

	/**  */
	void Draw(SDL_Renderer* Renderer);

	/**  */
	void AttachEntity(Entity* GameObject);

private:
	/** A list of all the entities currently ion the game world. */
	std::vector<Entity*> m_EntityList;
};
