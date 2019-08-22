#pragma once

#include "AI/FSM/State.h"

class Spaceship;
class FoundEnemy;
class FoundPath;

class Patrol : public State<Spaceship>
{
public:
	Patrol();
	~Patrol() = default;

	void OnEnter(std::shared_ptr<Spaceship> owner);
	void OnUpdate(std::shared_ptr<Spaceship> owner);
	void OnExit(std::shared_ptr<Spaceship> owner);
};

class Attack : public State<Spaceship>
{
public:
	Attack();
	~Attack() = default;

	void OnEnter(std::shared_ptr<Spaceship> owner);
	void OnUpdate(std::shared_ptr<Spaceship> owner);
	void OnExit(std::shared_ptr<Spaceship> owner);
};