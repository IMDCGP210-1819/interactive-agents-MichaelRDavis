#pragma once

#include "Gameplay/ECS/Entity.h"
#include "AI/Steering/SteeringBehavior.h"

class SpriteComponent;

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

	// Entity Interface
	void Update(float DeltaTime) override;

private:
	/** Asteroid AI driven behavior. */
	std::unique_ptr<SteeringBehavior> m_Behavior;

	/** Asteroid sprite component. */
	std::unique_ptr<SpriteComponent> m_Sprite;
};
