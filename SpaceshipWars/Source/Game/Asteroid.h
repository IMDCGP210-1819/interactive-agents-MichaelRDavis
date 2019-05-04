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

	// Steering Behavior

	Vec2 Wander();

private:
	Vec2 m_circleCenter;
	float m_cirleDistance;
};
