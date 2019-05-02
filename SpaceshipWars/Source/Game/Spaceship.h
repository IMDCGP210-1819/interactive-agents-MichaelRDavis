#pragma once

#include "GameObject/Entity.h"
#include "AI/FSM/IState.h"

#include "Game/Projectile.h"

template<typename T>
class IState;

template<typename T>
class TFiniteStateMachine;

class SpriteComponent;

/**
 * 
 */
class Spaceship : public Entity
{
public:
	/** Default constructor. */
	Spaceship();

	/** Default destructor. */
	~Spaceship();

	// Entity interface
	void Initialize(SDL_Renderer* Renderer) override;
	void Update(float DeltaTime) override;
	void Draw() override;

	/** Fire projectile. */
	void Fire();

	/** Return true if we can fire right now. */
	bool CanFire();

	/** Return true if dead. */
	inline bool IsDead() const
	{
		return m_Health <= 0;
	}

	inline int GetHealth() const { return m_Health; }
	inline int GetMaxHealth() const { return m_MaxHealth; }
	inline int GetAmmo() const { return m_Ammo; }
	inline int GetMaxAmmo() const { return m_MaxAmmo; }

private:
	/** Spaceship AI behavior. */
	std::unique_ptr<TFiniteStateMachine<Spaceship>> m_FSM;

	/** Projectile class to fire. */
	std::unique_ptr<Projectile> m_Bullet;

	/** Current health of the spaceship. */
	int m_Health;

	/** Max health of the spaceship. */
	int m_MaxHealth;

	/** Current ammo. */
	int m_Ammo;

	/** Max ammo. */
	int m_MaxAmmo;
};