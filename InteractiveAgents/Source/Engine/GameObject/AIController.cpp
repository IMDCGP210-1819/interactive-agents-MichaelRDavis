#include "AIController.h"
#include "AI/Pathfinding/AStar.h"
#include "AI/Navigation/NavGraph.h"
#include "AI/Navigation/NavPath.h"
#include "AI/Navigation/NavNode.h"
#include "Entity.h"
#include "World.h"

AIController::AIController(Entity* entity)
	: m_owner(entity)
{
	m_navigation = std::make_shared<AStar>();
}

AIController::~AIController()
{

}

void AIController::MoveTo(Vector2f position)
{
	Vector2f direction = position - m_owner->GetPosition();
	float angle = atan2(-direction.y, direction.x);
	m_owner->SetRotation(angle);
}

void AIController::MoveToRandomNode()
{
	NavNode* startNode = m_owner->GetWorld()->GetNavGraph()->GetRandomNode();
	NavNode* goalNode = m_owner->GetWorld()->GetNavGraph()->GetRandomNode();

	NavPath* path = m_navigation->Search(startNode, goalNode);
	for (auto node : path->path)
	{
		MoveTo(node->position);
	}
}

void AIController::SetOwner(Entity* newOwner)
{
	m_owner = newOwner;
}
