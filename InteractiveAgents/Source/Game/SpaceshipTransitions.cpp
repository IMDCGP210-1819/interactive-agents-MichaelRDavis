#include "SpaceshipTransitions.h"
#include "SpaceshipStates.h"
#include "Spaceship.h"
#include <iostream>

FoundEnemy::FoundEnemy(std::shared_ptr<Attack> state)
	: Transition(state)
{
	m_nextState = state;
}

bool FoundEnemy::IsValid(Spaceship* owner)
{
	if (owner->CanSeeEnemy() && owner->CanFire())
	{
		return true;
	}

	return false;
}

std::shared_ptr<State<Spaceship>> FoundEnemy::GetNextState()
{
	return m_nextState;
}

void FoundEnemy::OnTransition()
{
	std::cout << "Enemy spaceship detected" << std::endl;
}

FoundPath::FoundPath(std::shared_ptr<Patrol> state)
	: Transition(state)
{
	m_nextState = state;
}

bool FoundPath::IsValid(Spaceship* owner)
{
	// TODO: Check if a random node is found
	return false;
}

std::shared_ptr<State<Spaceship>> FoundPath::GetNextState()
{
	return m_nextState;
}

void FoundPath::OnTransition()
{
	std::cout << "Navigation path found" << std::endl;
}

CanFlee::CanFlee(std::shared_ptr<Flee> state)
	: Transition(state)
{
	m_nextState = state;
}

bool CanFlee::IsValid(Spaceship* owner)
{
	if (owner->GetHealth() < 5)
	{
		return true;
	}

	return false;
}

std::shared_ptr<State<Spaceship>> CanFlee::GetNextState()
{
	return m_nextState;
}

void CanFlee::OnTransition()
{
	std::cout << "Low on Health and Ammo find some!" << std::endl;
}
