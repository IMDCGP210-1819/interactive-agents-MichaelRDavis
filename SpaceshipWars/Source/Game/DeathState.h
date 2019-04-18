#pragma once

#include "GameSystems/AI/FSM/IState.h"

class Spaceship;

class DeathState : public IState<Spaceship>
{
public:
	void OnEnter(Spaceship* Owner) override;
	void OnExecute(Spaceship* Owner) override;
	void OnExit(Spaceship* Owner) override;
};