#include "Steering.h"
#include "Math/Math.h"
#include "Entity.h"

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

Vector2f Steering::Seek(Entity* target)
{
	Vector2f result;
	result = target->GetPosition() - m_owner->GetPosition();
	result.normalize();
	result *= m_owner->GetSpeed();

	m_owner->SetRotation(CalculateOrientation(m_owner->GetRotation(), result));

	return result;
}

Vector2f Steering::Flee(Entity* target)
{
	Vector2f result;
	result = m_owner->GetPosition() - target->GetPosition();
	result.normalize();
	result *= m_owner->GetSpeed();

	m_owner->SetRotation(CalculateOrientation(m_owner->GetRotation(), result));

	return result;
}

Vector2f Steering::Arrive(Entity* target)
{
	Vector2f result;
	float radius = 2.0f;
	float timeToTarget = 0.25f;

	result = target->GetPosition() - m_owner->GetPosition();
	if (result.length() < radius)
	{
		return Vector2f(0.0f, 0.0f);
	}

	result /= timeToTarget;
	if (result.length() > m_owner->GetSpeed())
	{
		result.normalize();
		result *= m_owner->GetSpeed();
	}

	m_owner->SetRotation(CalculateOrientation(m_owner->GetRotation(), result));

	return result;
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
	float randVal = rand.GetRangef(-1000.0f, 1000.0f);
	float displacementTime = m_displacement * deltaTime;
	m_force += Vector2f(randVal, randVal);
	m_force.normalize();
	m_force *= m_circleRadius;
	Vector2f targetVector = m_force + Vector2f(m_circleDist, 0.0f);
	return targetVector - m_owner->GetPosition();
}

float Steering::CalculateOrientation(float currentOrientation, Vector2f currentVelocity)
{
	if (currentVelocity.length() > 0)
	{
		return atan2(-currentVelocity.x, -currentVelocity.y);
	}
	else
	{
		return currentOrientation;
	}
}
