#pragma once

#include "Entity.h"

class AIController;
class SpaceshipFSM;
class Projectile;

class Spaceship : public Entity
{
public:
	Spaceship(World* world);
	~Spaceship();

	void MoveTo();
	void Fire();

	void Update(float deltaTime) override;

	void CanSeeEnemy();

	bool IsDead();
	bool CanFire();

	inline int32_t GetHealth() const
	{
		return m_health;
	}

	inline int32_t GetAmmo() const
	{
		return m_ammo;
	}

	inline bool IsDead() const
	{
		return m_isDead;
	}

private:
	std::unique_ptr<AIController> m_ai;
	std::unique_ptr<SpaceshipFSM> m_fsm;
	std::unique_ptr<Projectile> m_bullet;

	int32_t m_health;
	int32_t m_ammo;
	bool m_isDead;
};