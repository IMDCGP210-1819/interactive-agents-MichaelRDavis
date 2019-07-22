#pragma once

#include "AI/FSM/FSM.h"

class Spaceship;

class SpaceshipFSM : public FSM<Spaceship>
{
public:
	SpaceshipFSM();
	~SpaceshipFSM();

	void Update();
};