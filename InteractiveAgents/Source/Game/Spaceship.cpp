#include "Spaceship.h"
#include "SpaceshipFSM.h"
#include "GameObject/World.h"
#include "Projectile.h"
#include "AI/Pathfinding/AStar.h"
#include "AI/Steering/Steering.h"

Spaceship::Spaceship(World* world)
	: Entity(world)
{
	m_fsm = std::make_shared<SpaceshipFSM>();
	m_fsm->SetOwner(this);
	m_navigation = std::make_shared<AStar>();
	m_steering = std::make_shared<Steering>();
	m_steering->SetOwner(this);

	m_health = 100;
	m_ammo = 50;
	m_isDead = false;
}

Spaceship::~Spaceship()
{

}

void Spaceship::TakeDamage(int32_t damage)
{
	if (damage > 0)
	{
		m_health -= damage;
	}
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
	m_bullet = std::make_unique<Projectile>(GetWorld());
}

void Spaceship::MoveTo(Vector2f position)
{
	Vector2f direction = position - GetPosition();
	float angle = atan2(-direction.y, direction.x);
	SetRotation(angle);
}

void Spaceship::Update(float deltaTime)
{
	m_fsm->Update();
}

bool Spaceship::CanSeeEnemy()
{
	// TODO: Ray trace for an enemy spaceship
	return false;
}

void Spaceship::SetTargetEnemy(Spaceship* target)
{
	m_target = target;
}

void Spaceship::FleeFromEnemy()
{

}

bool Spaceship::CanFire()
{
	return m_ammo > 0 && !IsDead();
}

bool Spaceship::IsDead()
{
	return m_health <= 0;
}

