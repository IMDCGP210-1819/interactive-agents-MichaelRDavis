#include "stdafx.h"
#include "Spaceship.h"
#include "AI/FSM/FiniteStateMachine.h"
#include "AI/SteeringBehavior/SteeringBehavior.h"

Spaceship::Spaceship(SDL_Renderer* renderer)
	: Entity(renderer)
{
	m_FSM = std::make_unique<TFiniteStateMachine<Spaceship>>(this);
	m_behavior = std::make_unique<SteeringBehavior>();
	m_radius = 5.0f;
}

Spaceship::~Spaceship()
{

}

void Spaceship::Initialize()
{
	Entity::Initialize();
}

void Spaceship::Update(float DeltaTime)
{
	Entity::Update(DeltaTime);
	if (m_isActive)
	{
		m_FSM->OnUpdate();
	}
}

void Spaceship::Draw()
{
	Entity::Draw();
}

bool Spaceship::CanTakeDamage(int32_t damage)
{
	return GetIsActive() && damage > 0 && !IsDead();
}

void Spaceship::TakeDamage(int32_t damage, Entity* otherEntity)
{
	if (CanTakeDamage(damage))
	{
		m_Health -= damage;
		if (m_Health <= 0)
		{
			m_Health = 0;
			Disable();
		}
	}
}

void Spaceship::Fire()
{
	if (CanFire())
	{
		m_Bullet = std::make_unique<Projectile>(m_renderer);
		m_Bullet->SetOwner(std::make_shared<Entity>(*this));
		--m_Ammo;
	}
}

bool Spaceship::CanFire()
{
	return m_Ammo > 0 || m_Health > 0;
}
