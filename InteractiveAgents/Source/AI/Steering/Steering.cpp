#include "Steering.h"
#include "Math/Math.h"
#include "Game/Entity.h"

Steering::Steering()
{
	m_owner = nullptr;
	m_force = Vector2f(0.0f, 0.0f);
	m_circleRadius = 1.3f;
	m_circleDist = 2.0f;
	m_displacement = 80.0f;
}

Steering::Steering(Entity* entity)
	: m_owner(entity)
{
	m_force = Vector2f(0.0f, 0.0f);
	m_circleRadius = 1.3f;
	m_circleDist = 2.0f;
	m_displacement = 80.0f;
}

void Steering::SetOwner(Entity* newOwner)
{
	m_owner = newOwner;
}

void Steering::SetForce(Vector2f newForce)
{
	m_force = newForce;
}

void Steering::SetCircleRadius(float newRadius)
{
	m_circleRadius = newRadius;
}

void Steering::SetCircleDistance(float newDistance)
{
	m_circleDist = newDistance;
}

void Steering::SetDisplacement(float newDisplacement)
{
	m_displacement = newDisplacement;
}

Vector2f Steering::Wander(float deltaTime)
{ 
	Random rand;
	float randVal = rand.GetRange<float>(-1000.0f, 1000.0f);
	float displacementTime = m_displacement * deltaTime;
	m_force += Vector2f(randVal, randVal);
	m_force.normalize();
	m_force *= m_circleRadius;
	Vector2f targetVector = m_force + Vector2f(m_circleDist, 0.0f);
	return targetVector - m_owner->GetPosition();
}
