#include "SpaceshipTransitions.h"
#include "SpaceshipStates.h"
#include <iostream>

FoundEnemy::FoundEnemy(std::shared_ptr<Attack> state)
	: Transition(state)
{
	m_nextState = state;
}

bool FoundEnemy::IsValid()
{
	// TODO: Check if enemy is in range 
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

bool FoundPath::IsValid()
{
	// TODO: Check if a valid path is found
	return true;
}

std::shared_ptr<State<Spaceship>> FoundPath::GetNextState()
{
	return m_nextState;
}

void FoundPath::OnTransition()
{
	std::cout << "Navigation path found" << std::endl;
}
