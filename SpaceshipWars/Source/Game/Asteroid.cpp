#include "stdafx.h"
#include "Asteroid.h"
#include "Math/Vector.h"

Asteroid::Asteroid(SDL_Renderer* renderer)
	: Entity(renderer)
{
	m_Behavior = std::make_unique<SteeringBehavior>();
}

Asteroid::~Asteroid()
{

}

void Asteroid::Initialize()
{
	
}

void Asteroid::Update(float DelaTime)
{

}

void Asteroid::Draw()
{

}
