#pragma once

#include "AI/FSM/IState.h"

class Spaceship;

class FireState : public IState<Spaceship>
{
public:
	void OnEnter() override;
	void OnExecute() override;
	void OnExit() override;
};