#include "GamePCH.h"
#include "AttackState.h"
#include "Spaceship.h"

void AttackState::OnEnter(Spaceship* Owner)
{
	// Check if enemy spaceship is within range.
	// Check if spaceship has ammo.
	// Check if spaceship is not dead.
}

void AttackState::OnExecute(Spaceship* Owner)
{
	// Fire at enemy spaceship if in range.
	Owner->Fire();
}

void AttackState::OnExit(Spaceship* Owner)
{
	// If out of ammo leave this state.
	// If dead leave this state.
	// If out of range exit state.
}
