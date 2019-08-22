#pragma once

#include "AI/FSM/FSM.h"

class Spaceship;
class Attack;
class Patrol;
class FoundPath;
class FoundEnemy;

class SpaceshipFSM : public FSM<Spaceship>
{
public:
	SpaceshipFSM();
	~SpaceshipFSM();

	void Update();

private:
	std::shared_ptr<Attack> m_attack;
	std::shared_ptr<Patrol> m_patrol;
	std::shared_ptr<FoundPath> m_foundPath;
	std::shared_ptr<FoundEnemy> m_foundEnemy;
};