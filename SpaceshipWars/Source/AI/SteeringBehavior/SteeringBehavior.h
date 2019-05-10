#pragma once

#include "Math/Vector.h"

class Entity;

/**
 * 
 */
class SteeringBehavior
{
public:
	/** Default constructor. */
	SteeringBehavior();

	/** Default destructor. */
	~SteeringBehavior();

	/** Calculate the wander force. */
	Vec2 Wander(float deltaTime);

	/** Set the owner of this steering behavior. */
	void SetOwner(Entity* otherEntity);

	/** Set the target entity */
	void SetTargetEntity(Entity* targetEntity);

private:
	/** Owner of this steering behavior. */
	Entity* m_owner;

	/** target entity. */
	Entity* m_targetEntity;

	/** Steering force. */
	Vec2 m_force;

	/** Amount of wander force. */
	Vec2 m_wander;

	/** Radius of the circle. */
	float m_circleRadius;

	/** Distance of the circle. */
	float m_circleDist;

	/** Wander displacement. */
	float m_displacement;
};