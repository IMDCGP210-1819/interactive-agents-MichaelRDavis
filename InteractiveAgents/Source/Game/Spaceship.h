#pragma once

#include "GameObject/Entity.h"

class AIController;
class SpaceshipFSM;
class Projectile;
class AStar;
class Steering;

class Spaceship : public Entity, public std::enable_shared_from_this<Spaceship>
{
public:
	/** Default Spaceship constructor */
	Spaceship(World* world);

	/** Default Spaceship destructor */
	~Spaceship();

	/** Factory function to create a spaceship */
	template<typename ... T>
	static std::shared_ptr<Spaceship> CreateSpaceship(T&& ... args)
	{
		return std::shared_ptr<Spaceship>(new Spaceship(std::forward<T>(args)...));
	}

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

	/** Returns true if enemy is within sight */
	bool CanSeeEnemy();

	/** Set the target enemy to follow */
	void SetTargetEnemy(Spaceship* target);

	/** Flee from the enemy spaceship */
	void FleeFromEnemy();

	/** Returns true if spaceship destroyed */
	bool IsDead();

	/** Returns true if we can fire  */
	bool CanFire();

	/** Returns the current health */
	inline int32_t GetHealth() const
	{
		return m_health;
	}

	/** Returns the current ammo count */
	inline int32_t GetAmmo() const
	{
		return m_ammo;
	}

	/** Returns true if spaceship is destroyed, i.e. when out of health */
	inline bool IsDead() const
	{
		return m_isDead;
	}

	inline bool HasTarget() const
	{
		return m_target != nullptr;
	}

	/** Returns a this pointer to the the spaceship */
	std::shared_ptr<Spaceship> GetSpaceship()
	{
		return shared_from_this();
	}

	/** Returns a pointer to the state machine */
	inline std::shared_ptr<SpaceshipFSM> GetStateMachine() const
	{
		return m_fsm;
	}

	/** Returns a pointer a pointer to the navigation system */
	inline std::shared_ptr<AStar> GetNavigation() const
	{
		return m_navigation;
	}

	inline std::shared_ptr<Steering> GetSteering() const
	{
		return m_steering;
	}

	inline Spaceship* GetTargetEnemy() const
	{
		return m_target;
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