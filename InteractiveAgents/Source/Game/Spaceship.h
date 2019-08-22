#pragma once

#include "GameObject/Entity.h"

class AIController;
class SpaceshipFSM;
class Projectile;

class Spaceship : public Entity
{
public:
	/** Default Spaceship constructor */
	Spaceship(World* world);

	/** Default Spaceship destructor */
	~Spaceship();

	/** Take damage on hit */
	void TakeDamage(int32_t damage);

	/** Called once per frame */
	void Update(float deltaTime) override;

	/** Use ammo, if firing */
	void UseAmmo();

	/** Fire projectile */
	void Fire();

	void CanSeeEnemy();

	/** Returns true if spaceship destroyed */
	bool IsDead();

	/** Returns true if we can fire  */
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

	inline std::shared_ptr<AIController> GetAIController()
	{
		return m_ai;
	}

private:
	std::shared_ptr<AIController> m_ai;
	std::shared_ptr<SpaceshipFSM> m_fsm;
	std::unique_ptr<Projectile> m_bullet;

	int32_t m_health;
	int32_t m_ammo;
	bool m_isDead;
};