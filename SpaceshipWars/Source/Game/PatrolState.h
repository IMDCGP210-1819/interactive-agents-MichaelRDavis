#pragma once

#include "GameSystems/AI/FSM/IState.h"

class Spaceship;

class PatrolState : public IState<Spaceship>
{
public:
	// IState interface
	void OnEnter(Spaceship* Owner) override;
	void OnExecute(Spaceship* Owner) override;
	void OnExit(Spaceship* Owner) override;
};