#include "SpaceshipStates.h"
#include "Spaceship.h"
#include "SpaceshipTransitions.h"

Patrol::Patrol()
{

}

void Patrol::OnEnter(std::shared_ptr<Spaceship> owner)
{
	owner->SetSpeed(0.5f);
}

void Patrol::OnUpdate(std::shared_ptr<Spaceship> owner)
{
	owner->FollowNavigationPath();
}

void Patrol::OnExit(std::shared_ptr<Spaceship> owner)
{
	owner->SetSpeed(1.0f);
}

Attack::Attack()
{

}

void Attack::OnEnter(std::shared_ptr<Spaceship> owner)
{
	owner->SetSpeed(1.5f);
}

void Attack::OnUpdate(std::shared_ptr<Spaceship> owner)
{
	owner->SeekEnemy();

	// TODO: Check if facing enemy spaceship
	owner->Fire();
}

void Attack::OnExit(std::shared_ptr<Spaceship> owner)
{
	owner->SetSpeed(1.0f);
}

Flee::Flee()
{

}

void Flee::OnEnter(std::shared_ptr<Spaceship> owner)
{
	owner->SetSpeed(2.5f);
}

void Flee::OnUpdate(std::shared_ptr<Spaceship> owner)
{
	owner->FleeFromEnemy();
}

void Flee::OnExit(std::shared_ptr<Spaceship> owner)
{
	owner->SetSpeed(1.0f);
}
