#pragma once

#include "Gameplay/GameObject/Entity.h"
#include "GameSystems/AI/FSM/IState.h"

#include "Game/Projectile.h"

template<typename T>
class IState;

template<typename T>
class FiniteStateMachine;

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
	void Initialize() override;
	void Update(float DeltaTime) override;
	void Render() override;

	/** Return true if dead. */
	inline bool IsDead() const
	{
		return m_Health <= 0;
	}

private:
	/** Spaceship AI behavior. */
	std::unique_ptr<FiniteStateMachine<Spaceship>> m_FSM;

	/** Spaceship sprite component. */
	std::unique_ptr<SpriteComponent> m_Sprite;

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