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

	void OnEnter(Spaceship* owner);
	void OnUpdate(Spaceship* owner);
	void OnExit(Spaceship* owner);
};

class Attack : public State<Spaceship>
{
public:
	Attack();
	~Attack() = default;

	void OnEnter(Spaceship* owner);
	void OnUpdate(Spaceship* owner);
	void OnExit(Spaceship* owner);
};

class Flee : public State<Spaceship>
{
public:
	Flee();
	~Flee() = default;

	void OnEnter(Spaceship* owner);
	void OnUpdate(Spaceship* owner);
	void OnExit(Spaceship* owner);
};