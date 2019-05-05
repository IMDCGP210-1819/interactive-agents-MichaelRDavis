#pragma once

#include "GameObject/Entity.h"

class SteeringBehavior;

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

	/** Apply damage upon collision with another entity. */
	void ApplyDamage(int32_t damage, Entity* otherEntity = nullptr);

private:
	/** Behavior of the asteroid. */
	std::unique_ptr<SteeringBehavior> m_behavior;
};
