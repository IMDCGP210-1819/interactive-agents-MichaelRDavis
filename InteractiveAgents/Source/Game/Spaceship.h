#pragma once

#include "GameObject/Entity.h"

class AIController;
class SpaceshipFSM;
class Projectile;
class AStar;
class Steering;

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

	/** Move to position; */
	void MoveTo(Vector2f position);

	/** Move to a random node */
	void MoveToRandomNode();

	/** Returns true if enemy is within sight */
	bool CanSeeEnemy();

	/** Set the target enemy to follow */
	void SetTargetEnemy(Spaceship* target);

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

private:
	std::shared_ptr<AStar> m_navigation;
	std::shared_ptr<SpaceshipFSM> m_fsm;
	std::shared_ptr<Steering> m_steering;
	std::unique_ptr<Projectile> m_bullet;
	Spaceship* m_target;

	int32_t m_health;
	int32_t m_ammo;
	bool m_isDead;
};