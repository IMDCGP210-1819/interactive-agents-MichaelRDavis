#pragma once

#include "Gameplay/GameObject/Entity.h"
#include "GameSystems/AI/Steering/SteeringBehavior.h"

class SpriteComponent;

/**
 * 
 */
class Asteroid : public Entity
{
public:
	/** Default constructor. */
	Asteroid();

	/**  */
	Asteroid(int SpriteID, std::string Filename);

	/** Default destructor. */
	~Asteroid();

	// Entity interface
	void Initialize() override;
	void Update(float DeltaTime) override;
	void Render() override;

private:
	/** Asteroid AI driven behavior. */
	std::unique_ptr<SteeringBehavior> m_Behavior;

	/** Asteroid sprite component. */
	std::unique_ptr<SpriteComponent> m_Sprite;
};
