#pragma once

class Entity;

class World
{
public:
	World();
	~World();

	virtual void Initialize();
	virtual void Update(float DeltaTime);
	virtual void Render();

	inline const std::vector<Entity*> GetEntities() const { return m_Entities; }

private:
	std::vector<Entity*> m_Entities;
};
