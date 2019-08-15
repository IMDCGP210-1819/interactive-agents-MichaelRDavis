#include "SpaceshipTransitions.h"
#include "SpaceshipStates.h"
#include <iostream>

FoundEnemy::FoundEnemy()
{
	//m_attack = std::make_shared<Attack>();
}

bool FoundEnemy::IsValid()
{
	// TODO: Check if enemy is in range 
	return false;
}

std::shared_ptr<State<Spaceship>> FoundEnemy::GetNextState()
{
	//return m_attack;
	return nullptr;
}

void FoundEnemy::OnTransition()
{
	std::cout << "Enemy spaceship detected" << std::endl;
}

FoundPath::FoundPath()
{
	//m_patrol = std::make_shared<Patrol>();
}

bool FoundPath::IsValid()
{
	// TODO: Check if a valid path is found
	return true;
}

std::shared_ptr<State<Spaceship>> FoundPath::GetNextState()
{
	//return m_patrol;
	return nullptr;
}

void FoundPath::OnTransition()
{
	std::cout << "Navigation path found" << std::endl;
}
