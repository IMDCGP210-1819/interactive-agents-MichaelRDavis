#pragma once

#include <memory>
#include <vmath.h>

class AStar;
class Entity;

/**
 * 
 */
class AIController
{
public:
	AIController(Entity* entity);
	~AIController();

	void MoveTo(Vector2f position);

	void MoveToRandomNode();

	void SetOwner(Entity* newOwner);

	inline std::shared_ptr<AStar> GetNavigation() const
	{
		return m_navigation;
	}

	inline Entity* GetOwner() const
	{
		return m_owner;
	}

protected:
	Entity* m_owner;
	std::shared_ptr<AStar> m_navigation;
};