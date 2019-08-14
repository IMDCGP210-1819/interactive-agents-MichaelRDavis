#include "SpaceshipStates.h"
#include "Spaceship.h"

void Patrol::OnEnter(std::shared_ptr<Spaceship> owner)
{

}

void Patrol::OnUpdate(std::shared_ptr<Spaceship> owner)
{
	
}

void Patrol::OnExit(std::shared_ptr<Spaceship> owner)
{

}

void Attack::OnEnter(std::shared_ptr<Spaceship> owner)
{

}

void Attack::OnUpdate(std::shared_ptr<Spaceship> owner)
{
	//owner->Fire();
}

void Attack::OnExit(std::shared_ptr<Spaceship> owner)
{

}
