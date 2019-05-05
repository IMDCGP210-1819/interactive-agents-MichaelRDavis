#pragma once

#include "Math/Vector.h"

class Entity;

class SteeringBehavior
{
public:
	SteeringBehavior();
	~SteeringBehavior();

	Vec2 Wander(float deltaTime);

	void SetOwner(Entity* otherEntity);
	void SetTargetEntity(Entity* targetEntity);

private:
	Entity* m_owner;
	Entity* m_targetEntity;

	Vec2 m_force;

	Vec2 m_wander;
	float m_circleRadius;
	float m_circleDist;
	float m_displacement;
};