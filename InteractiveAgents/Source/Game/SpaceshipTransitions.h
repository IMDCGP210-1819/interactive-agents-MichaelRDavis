#pragma once

#include "AI/FSM/Transition.h"

class Spaceship;
class Attack;

class FoundEnemy : Transition<Spaceship>
{
public:
	FoundEnemy();
	~FoundEnemy() = default;

	bool IsValid();
	std::shared_ptr<State<Spaceship>> GetNextState();
	void OnTransition();

private:
	std::shared_ptr<Attack> m_attack;
};