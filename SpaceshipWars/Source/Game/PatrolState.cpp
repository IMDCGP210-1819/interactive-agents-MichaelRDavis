#include "stdafx.h"
#include "PatrolState.h"

void PatrolState::OnEnter(Spaceship* Owner)
{
	// Find a random navigation node in the navigation graph.
}

void PatrolState::OnExecute(Spaceship* Owner)
{
	// Move to random navigation node in the navigation graph.
}

void PatrolState::OnExit(Spaceship* Owner)
{
	// Exit if spaceship is in range.
	// Exit if out of ammo.
	// Exit if dead.
}

