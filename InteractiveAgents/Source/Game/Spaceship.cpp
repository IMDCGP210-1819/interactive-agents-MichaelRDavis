#include "Spaceship.h"
#include "SpaceshipFSM.h"
#include "World.h"

Spaceship::Spaceship(World* world)
	: Entity(world)
{
	m_fsm = std::make_unique<SpaceshipFSM>();

	m_health = 100;
	m_isDead = false;
}

Spaceship::~Spaceship()
{

}

void Spaceship::MoveTo()
{

}

void Spaceship::Update(float deltaTime)
{

}

