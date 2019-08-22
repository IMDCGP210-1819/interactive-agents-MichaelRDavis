#pragma once

#include "AI/FSM/Transition.h"

class Spaceship;
class Attack;
class Patrol;
class Flee;

class FoundEnemy : public Transition<Spaceship>
{
public:
	FoundEnemy(std::shared_ptr<Attack> state);
	~FoundEnemy() = default;

	bool IsValid(std::shared_ptr<Spaceship> owner);
	std::shared_ptr<State<Spaceship>> GetNextState();
	void OnTransition();
};

class FoundPath : public Transition<Spaceship>
{
public:
	FoundPath(std::shared_ptr<Patrol> state);
	~FoundPath() = default;

	bool IsValid(std::shared_ptr<Spaceship> owner);
	std::shared_ptr<State<Spaceship>> GetNextState();
	void OnTransition();
};

class CanFlee : public Transition<Spaceship>
{
public:
	CanFlee(std::shared_ptr<Flee> state);
	~CanFlee() = default;

	bool IsValid(std::shared_ptr<Spaceship> owner);
	std::shared_ptr<State<Spaceship>> GetNextState();
	void OnTransition();
};