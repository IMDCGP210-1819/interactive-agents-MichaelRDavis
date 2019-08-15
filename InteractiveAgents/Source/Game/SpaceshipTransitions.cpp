#include "SpaceshipTransitions.h"
#include "SpaceshipStates.h"

FoundEnemy::FoundEnemy()
{
	m_attack = std::make_shared<Attack>();
}

bool FoundEnemy::IsValid()
{
	return true;
}

std::shared_ptr<State<Spaceship>> FoundEnemy::GetNextState()
{
	return m_attack;
}

void FoundEnemy::OnTransition()
{

}
