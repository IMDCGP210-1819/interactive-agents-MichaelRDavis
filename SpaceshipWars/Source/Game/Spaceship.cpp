#include "stdafx.h"
#include "Spaceship.h"
#include "AI/FSM/FiniteStateMachine.h"

Spaceship::Spaceship()
{
	m_FSM = std::make_unique<TFiniteStateMachine<Spaceship>>(this);
}

Spaceship::~Spaceship()
{

}

void Spaceship::Initialize(SDL_Renderer* Renderer)
{
	m_renderer = Renderer;
}

void Spaceship::Update(float DeltaTime)
{
	m_FSM->OnUpdate();
}

void Spaceship::Draw()
{

}

void Spaceship::Fire()
{
	if (CanFire())
	{
		m_Bullet = std::make_unique<Projectile>();
		m_Bullet->SetOwner(std::make_shared<Entity>(*this));
	}
}

bool Spaceship::CanFire()
{
	return m_Ammo > 0 || m_Health > 0;
}
