#pragma once

class Entity;
class SceneNode;

class World
{
public:
	World();
	~World();

	virtual void Initialize();
	virtual void Update(float DeltaTime);
	virtual void Render();

	inline std::vector<Entity*> GetEntities() const { return m_Entities; }

private:
	SceneNode* m_SceneGraph;
	std::vector<Entity*> m_Entities;
};
