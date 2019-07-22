#pragma once

#include <vmath.h>

class Entity;

class Steering
{
public:
	Steering();
	Steering(Entity* entity);
	~Steering() = default;

	Vector2f Wander(float deltaTime);

	void SetOwner(Entity* newOwner);
	void SetForce(Vector2f newForce);
	void SetCircleRadius(float newRadius);
	void SetCircleDistance(float newDistance);
	void SetDisplacement(float newDisplacement);

	inline Entity* GetOwner() const { return m_owner; }
	inline Vector2f GetForce() const { return m_force; }
	inline float GetCircleRadius() const { return m_circleRadius; }
	inline float GetCircleDistance() const { return m_circleDist; }
	inline float GetDisplacement() const { return m_displacement; }

private:
	Entity* m_owner;

	Vector2f m_force;

	float m_circleRadius;
	float m_circleDist;
	float m_displacement;
};