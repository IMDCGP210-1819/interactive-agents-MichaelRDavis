#include "Spaceship.h"
#include "SpaceshipFSM.h"
#include "AI/Navigation/Grid.h"
#include "AI/Pathfinding/BreadthFirstSearch.h"
#include "World.h"

Spaceship::Spaceship(World* world)
	: Entity(world)
{
	m_fsm = std::make_unique<SpaceshipFSM>();
	m_bfs = std::make_unique<BreadthFirstSearch>(m_world->GetGrid().get());

	m_health = 100;
	m_isDead = false;
}

Spaceship::~Spaceship()
{

}

void Spaceship::MoveTo()
{
	//Node goalNode;
}

void Spaceship::Update(float deltaTime)
{

}

