#include "stdafx.h"
#include "Asteroid.h"
#include "Math/Vector.h"

Asteroid::Asteroid(SDL_Renderer* renderer)
	: Entity(renderer)
{
	
}

Asteroid::~Asteroid()
{

}

void Asteroid::Initialize()
{
	Entity::Initialize();
}

void Asteroid::Update(float deltaTime)
{
	Entity::Update(deltaTime);
}

void Asteroid::Draw()
{
	Entity::Draw();
}

Vec2 Asteroid::Wander()
{
	m_circleCenter = m_velocity;
	return m_circleCenter;
}
