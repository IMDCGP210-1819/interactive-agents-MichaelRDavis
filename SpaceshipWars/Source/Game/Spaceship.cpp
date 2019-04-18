#include "GamePCH.h"
#include "Spaceship.h"
#include "GameSystems/AI/FSM/FiniteStateMachine.h"
#include "Gameplay/Components/SpriteComponent.h"

Spaceship::Spaceship()
{
	m_FSM = std::make_unique<TFiniteStateMachine<Spaceship>>(this);
	m_Sprite = std::make_unique<SpriteComponent>();
}

Spaceship::~Spaceship()
{

}

void Spaceship::Initialize()
{

}

void Spaceship::Update(float DeltaTime)
{
	m_FSM->OnUpdate();
}

void Spaceship::Render()
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
