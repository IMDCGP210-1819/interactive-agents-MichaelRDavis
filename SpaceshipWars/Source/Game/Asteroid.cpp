#include "stdafx.h"
#include "Asteroid.h"
#include "Math/Vector.h"
#include "Spaceship.h"

Asteroid::Asteroid(SDL_Renderer* renderer)
	: Entity(renderer)
{
	
}

Asteroid::~Asteroid()
{

}

void Asteroid::Initialize()
{
	Entity::Initialize();
}

void Asteroid::Update(float deltaTime)
{
	Entity::Update(deltaTime);
}

void Asteroid::Draw()
{
	Entity::Draw();
}

void Asteroid::ApplyDamage(int32_t damage, Entity* otherEntity)
{
	if (Intersect(*otherEntity))
	{
		Spaceship* ship = dynamic_cast<Spaceship*>(otherEntity);
		if (!ship->IsDead())
		{

		}
	}
}

Vec2 Asteroid::Wander()
{
	m_circleCenter = m_velocity;
	m_circleCenter.Normalize();
	m_circleCenter *= m_cirleDistance;

	Vec2 disForce = Vec2::zeroVector;
	disForce *= m_circleRadius;

	return m_circleCenter;
}
