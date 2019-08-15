#pragma once

#include "AI/FSM/State.h"

class Spaceship;
class FoundEnemy;

class Patrol : public State<Spaceship>
{
public:
	Patrol();
	~Patrol();

	void OnEnter(std::shared_ptr<Spaceship> owner);
	void OnUpdate(std::shared_ptr<Spaceship> owner);
	void OnExit(std::shared_ptr<Spaceship> owner);

	std::shared_ptr<FoundEnemy> m_foundEnemy;
};

class Attack : public State<Spaceship>
{
public:
	Attack();
	~Attack();

	void OnEnter(std::shared_ptr<Spaceship> owner);
	void OnUpdate(std::shared_ptr<Spaceship> owner);
	void OnExit(std::shared_ptr<Spaceship> owner);
};