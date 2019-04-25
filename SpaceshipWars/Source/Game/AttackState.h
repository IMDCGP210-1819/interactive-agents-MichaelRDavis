#pragma once

#include "AI/FSM/IState.h"

class Spaceship;

class AttackState : public IState<Spaceship>
{
public:
	// IState interface.
	void OnEnter(Spaceship* Owner) override;
	void OnExecute(Spaceship* Owner) override;
	void OnExit(Spaceship* Owner) override;
};