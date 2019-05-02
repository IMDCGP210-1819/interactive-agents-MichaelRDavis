#pragma once

#include "GameObject/Entity.h"
#include "AI/Steering/SteeringBehavior.h"

/**
 * 
 */
class Asteroid : public Entity
{
public:
	/** Default constructor. */
	Asteroid();

	/** Default destructor. */
	~Asteroid();

	// Entity interface
	void Initialize(SDL_Renderer* Renderer) override;
	void Update(float DeltaTime) override;
	void Draw() override;

private:
	/** Asteroid AI driven behavior. */
	std::unique_ptr<SteeringBehavior> m_Behavior;
};
