#include "SpaceshipStates.h"
#include "Spaceship.h"
#include "SpaceshipTransitions.h"

Patrol::Patrol()
{

}

void Patrol::OnEnter(std::shared_ptr<Spaceship> owner)
{
	
}

void Patrol::OnUpdate(std::shared_ptr<Spaceship> owner)
{
	owner->MoveToRandomNode();
}

void Patrol::OnExit(std::shared_ptr<Spaceship> owner)
{

}

Attack::Attack()
{

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

Flee::Flee()
{

}

void Flee::OnEnter(std::shared_ptr<Spaceship> owner)
{

}

void Flee::OnUpdate(std::shared_ptr<Spaceship> owner)
{

}

void Flee::OnExit(std::shared_ptr<Spaceship> owner)
{

}
