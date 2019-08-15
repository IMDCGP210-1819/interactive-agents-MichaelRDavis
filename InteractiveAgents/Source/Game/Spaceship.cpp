#include "Spaceship.h"
#include "SpaceshipFSM.h"
#include "GameObject/World.h"
#include "Projectile.h"
#include "GameObject/AIController.h"

Spaceship::Spaceship(World* world)
	: Entity(world)
{
	m_fsm = std::make_unique<SpaceshipFSM>();
	m_ai = std::make_shared<AIController>(this);

	m_health = 100;
	m_ammo = 50;
	m_isDead = false;
}

Spaceship::~Spaceship()
{

}

void Spaceship::UseAmmo()
{
	m_ammo--;
	if (m_ammo <= 0)
	{
		m_ammo = 0;
	}
}

void Spaceship::Fire()
{
	if (CanFire())
	{
		UseAmmo();
		m_bullet = std::make_unique<Projectile>(GetWorld());
	}
}

void Spaceship::Update(float deltaTime)
{
	m_fsm->Update();
}

void Spaceship::CanSeeEnemy()
{
	// TODO: Ray trace for an enemy spaceship
}

bool Spaceship::CanFire()
{
	return m_ammo > 0 && !IsDead();
}

bool Spaceship::IsDead()
{
	return m_health <= 0;
}

