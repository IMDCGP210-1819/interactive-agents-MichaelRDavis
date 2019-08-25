#include "SpaceshipStates.h"
#include "Spaceship.h"
#include "SpaceshipTransitions.h"
#include "AI/Navigation/NavPath.h"
#include "AI/Navigation/NavNode.h"
#include "AI/Pathfinding/AStar.h"
#include "AI/Navigation/NavGraph.h"
#include "GameObject/World.h"
#include "AI/Steering/Steering.h"

Patrol::Patrol()
{

}

void Patrol::OnEnter(Spaceship* owner)
{
	owner->SetSpeed(1.2f);
}

void Patrol::OnUpdate(Spaceship* owner)
{
	NavNode* startNode = owner->GetWorld()->GetNavGraph()->GetRandomNode();
	NavNode* goalNode = owner->GetWorld()->GetNavGraph()->GetRandomNode();
	NavPath* path = owner->GetNavigation()->Find(startNode, goalNode);

	while (startNode != goalNode)
	{
		for (auto node : path->GetNavigationPath())
		{
			owner->MoveTo(node->position);

			if (node == goalNode)
			{
				goalNode = owner->GetWorld()->GetNavGraph()->GetRandomNode();
			}
		}
	}
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
	if (owner->HasTarget())
	{
		owner->GetSteering()->Seek(owner->GetTargetEnemy());
	}
}

void Attack::OnUpdate(Spaceship* owner)
{
	// TODO: Check if facing enemy spaceship
	if (owner->CanFire())
	{
		owner->UseAmmo();
		owner->Fire();
	}
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
	if (owner->HasTarget())
	{
		owner->GetSteering()->Flee(owner->GetTargetEnemy());
	}
}

void Flee::OnExit(Spaceship* owner)
{
	owner->SetSpeed(1.0f);
	owner->SetTargetEnemy(nullptr);
}
