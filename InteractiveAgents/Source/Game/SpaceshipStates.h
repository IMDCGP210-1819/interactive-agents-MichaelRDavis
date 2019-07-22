#pragma once

#include "AI/FSM/State.h"

class Spaceship;

class Patrol : public State<Spaceship>
{
	void OnEnter(std::shared_ptr<Spaceship> owner);
	void OnUpdate(std::shared_ptr<Spaceship> owner);
	void OnExit(std::shared_ptr<Spaceship> owner);
};

class Attack : public State<Spaceship>
{
	void OnEnter(std::shared_ptr<Spaceship> owner);
	void OnUpdate(std::shared_ptr<Spaceship> owner);
	void OnExit(std::shared_ptr<Spaceship> owner);
};