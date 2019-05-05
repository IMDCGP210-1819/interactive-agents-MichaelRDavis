#include "stdafx.h"
#include "Spaceship.h"
#include "AI/FSM/FiniteStateMachine.h"
#include "AI/SteeringBehavior/SteeringBehavior.h"

Spaceship::Spaceship(SDL_Renderer* renderer)
	: Entity(renderer)
{
	m_FSM = std::make_unique<TFiniteStateMachine<Spaceship>>(this);
	m_behavior = std::make_unique<SteeringBehavior>();
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
	m_FSM->OnUpdate();
}

void Spaceship::Draw()
{
	Entity::Draw();
}

void Spaceship::Fire()
{
	if (CanFire())
	{
		m_Bullet = std::make_unique<Projectile>(m_renderer);
		m_Bullet->SetOwner(std::make_shared<Entity>(*this));
	}
}

bool Spaceship::CanFire()
{
	return m_Ammo > 0 || m_Health > 0;
}
