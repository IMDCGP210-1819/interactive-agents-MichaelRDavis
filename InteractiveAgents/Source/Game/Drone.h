#pragma once

#include "GameObject/Entity.h"

class Steering;

class Drone : public Entity
{
public:
	Drone();
	~Drone();

private:
	std::unique_ptr<Steering> m_steering;
};