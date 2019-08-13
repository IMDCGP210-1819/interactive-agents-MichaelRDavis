#include "AIController.h"
#include "AI/Pathfinding/AStar.h"

AIController::AIController(Entity* entity)
	: m_owner(entity)
{
	m_navigation = std::make_shared<AStar>();
}

AIController::~AIController()
{

}

void AIController::SearchNavigationGraph(Vector2f& startLocation, Vector2f& endLocation)
{

}

void AIController::UpdateAIController()
{

}

void AIController::SetOwner(Entity* newOwner)
{
	m_owner = newOwner;
}
