#pragma once

#include "Entity.h"

class SpaceshipFSM;

class Spaceship : public Entity
{
public:
	Spaceship(World* world);
	~Spaceship();

	void MoveTo();

	void Update(float deltaTime) override;

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
	std::unique_ptr<SpaceshipFSM> m_fsm;

	int32_t m_health;
	int32_t m_ammo;
	bool m_isDead;
};