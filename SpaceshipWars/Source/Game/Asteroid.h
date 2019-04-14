#pragma once

#include "Gameplay/ECS/Entity.h"

class SteeringBehavior;

class Asteroid : public Entity
{
public:
	Asteroid();
	~Asteroid();

	void Update(float DeltaTime) override;

private:
	std::shared_ptr<SteeringBehavior> m_Behavior;
};
