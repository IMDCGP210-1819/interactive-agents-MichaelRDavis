#pragma once

#include "AI/FSM/FSM.h"

class Spaceship;
class Attack;
class Patrol;

class SpaceshipFSM : public FSM<Spaceship>
{
public:
	SpaceshipFSM();
	~SpaceshipFSM();

	void Update();

private:
	std::shared_ptr<Attack> m_attack;
	std::shared_ptr<Patrol> m_patrol;
};