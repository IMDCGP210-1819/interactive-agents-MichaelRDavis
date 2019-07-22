#pragma once

#include "Entity.h"

class Steering;

class Asteroid : public Entity
{
public:
	Asteroid(World* world);
	~Asteroid();

	void Update(float deltaTime) override;
	void Draw() override;

	void ApplyDamage(int32_t damage, Entity* otherEntity = nullptr);

private:
	std::unique_ptr<Steering> m_behavior;
};