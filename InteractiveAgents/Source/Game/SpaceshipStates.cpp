#include "SpaceshipStates.h"
#include "GameObject/AIController.h"
#include "Spaceship.h"
#include "SpaceshipTransitions.h"

Patrol::Patrol()
{
	m_foundEnemy = std::make_shared<FoundEnemy>();
	m_transitions.push_back(m_foundEnemy);
}

void Patrol::OnEnter(std::shared_ptr<Spaceship> owner)
{

}

void Patrol::OnUpdate(std::shared_ptr<Spaceship> owner)
{
	owner->GetAIController()->MoveToRandomNode();
}

void Patrol::OnExit(std::shared_ptr<Spaceship> owner)
{

}

Attack::Attack()
{
	m_foundPath = std::make_shared<FoundPath>();
	m_transitions.push_back(m_foundPath);
}

void Attack::OnEnter(std::shared_ptr<Spaceship> owner)
{

}

void Attack::OnUpdate(std::shared_ptr<Spaceship> owner)
{
	owner->Fire();
}

void Attack::OnExit(std::shared_ptr<Spaceship> owner)
{

}
