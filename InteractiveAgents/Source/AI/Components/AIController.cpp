#include "AIController.h"
#include "AI/Pathfinding/AStar.h"
#include "Game/Entity.h"

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

void AIController::FindPoint()
{

}

void AIController::SetOwner(Entity* newOwner)
{
	m_owner = newOwner;
}
