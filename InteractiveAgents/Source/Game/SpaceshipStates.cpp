#include "SpaceshipStates.h"
#include "Spaceship.h"
#include "SpaceshipTransitions.h"

Patrol::Patrol()
{

}

void Patrol::OnEnter(Spaceship* owner)
{
	owner->SetSpeed(1.2f);
}

void Patrol::OnUpdate(Spaceship* owner)
{
	owner->FollowNavigationPath();
}

void Patrol::OnExit(Spaceship* owner)
{
	owner->SetSpeed(1.0f);
}

Attack::Attack()
{

}

void Attack::OnEnter(Spaceship* owner)
{
	owner->SetSpeed(1.5f);
}

void Attack::OnUpdate(Spaceship* owner)
{
	owner->SeekEnemy();

	// TODO: Check if facing enemy spaceship
	owner->Fire();
}

void Attack::OnExit(Spaceship* owner)
{
	owner->SetSpeed(1.0f);
}

Flee::Flee()
{

}

void Flee::OnEnter(Spaceship* owner)
{
	owner->SetSpeed(2.5f);
}

void Flee::OnUpdate(Spaceship* owner)
{
	owner->FleeFromEnemy();
}

void Flee::OnExit(Spaceship* owner)
{
	owner->SetSpeed(1.0f);
}
