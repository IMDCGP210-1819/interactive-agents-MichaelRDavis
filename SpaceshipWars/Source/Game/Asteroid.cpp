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

void Asteroid::Initialize(SDL_Renderer* Renderer)
{
	m_renderer = Renderer;
}

void Asteroid::Update(float DelaTime)
{

}

void Asteroid::Draw()
{

}
