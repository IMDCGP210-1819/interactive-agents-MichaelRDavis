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
	void Initialize() override;
	void Update(float DeltaTime) override;
	void Draw(SDL_Renderer* Renderer) override;

private:
	/** Asteroid AI driven behavior. */
	std::unique_ptr<SteeringBehavior> m_Behavior;
};
