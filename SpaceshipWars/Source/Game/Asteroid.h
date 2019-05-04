#pragma once

#include "GameObject/Entity.h"

/**
 * 
 */
class Asteroid : public Entity
{
public:
	/** Default constructor. */
	Asteroid(SDL_Renderer* renderer);

	/** Default destructor. */
	~Asteroid();

	// Entity interface
	void Initialize() override;
	void Update(float deltaTime) override;
	void Draw() override;

	void ApplyDamage(int32_t damage, Entity* otherEntity);

	// Steering Behavior

	Vec2 Wander();

private:
	Vec2 m_circleCenter;
	float m_cirleDistance;
	float m_circleRadius;
	int32_t m_damage;
};
