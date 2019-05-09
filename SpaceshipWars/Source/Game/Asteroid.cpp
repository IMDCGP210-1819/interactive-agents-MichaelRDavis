#include "stdafx.h"
#include "Asteroid.h"
#include "Math/Vector.h"
#include "Spaceship.h"
#include "AI/SteeringBehavior/SteeringBehavior.h"

Asteroid::Asteroid(SDL_Renderer* renderer)
	: Entity(renderer)
{
	m_behavior = std::make_unique<SteeringBehavior>();
	m_behavior->SetOwner(this);
	m_maxSpeed = 0.05f;
	m_radius = 5.0f;
	m_mass = 1.0f;
	m_isActive = true;
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

	Constrain(m_position, 1920, 1080);
	Vec2 force = Vec2::zeroVector;
	force = m_behavior->Wander(deltaTime);
	force = force / m_mass;
	m_velocity += force * deltaTime;
	m_velocity.Truncate(m_maxSpeed);
	m_position += m_velocity * deltaTime;
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
			ship->TakeDamage(damage, otherEntity);
		}
	}
}
