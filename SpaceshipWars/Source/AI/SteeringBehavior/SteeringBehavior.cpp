#include "stdafx.h"
#include "SteeringBehavior.h"
#include "Math/Random.h"
#include "GameObject/Entity.h"

SteeringBehavior::SteeringBehavior()
{
	m_circleRadius = 1.2f;
	m_circleDist = 2.0f;
	m_displacement = 80.0f;
}

SteeringBehavior::~SteeringBehavior()
{

}

Vec2 SteeringBehavior::Wander(float deltaTime)
{
	float displacementTime = m_displacement * deltaTime;
	float randVal = std::clamp(Random::Rand(), 1000.0f, 1000.0f) * displacementTime;
	m_wander += Vec2(randVal, randVal);
	m_wander.Normalize();
	m_wander *= m_circleRadius;
	Vec2 targetVector = m_wander + Vec2(m_circleDist, 0);
	return targetVector - m_owner->GetPosition();
}

void SteeringBehavior::SetOwner(Entity* otherEntity)
{
	m_owner = otherEntity;
}

void SteeringBehavior::SetTargetEntity(Entity* targetEntity)
{
	m_targetEntity = targetEntity;
}
