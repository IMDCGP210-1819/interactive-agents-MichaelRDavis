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
	m_radius = 1.0f;
	m_mass = 1.0f;
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

	Vec2 force;
	force = m_behavior->Wander(deltaTime);
	Vec2 accel = force / m_mass;
	m_velocity += accel * deltaTime;
	m_velocity.Truncate(m_maxSpeed);
	m_position += m_velocity * deltaTime;

	Constrain(m_position, 1920, 1080);

	//ApplyDamage(10);
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
