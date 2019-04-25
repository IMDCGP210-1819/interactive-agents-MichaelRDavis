#include "stdafx.h"
#include "Asteroid.h"
#include "Math/Vector.h"


Asteroid::Asteroid()
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

void Asteroid::Draw(SDL_Renderer* Renderer)
{

}
