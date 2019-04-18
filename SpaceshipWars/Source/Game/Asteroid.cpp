#include "GamePCH.h"
#include "Asteroid.h"
#include "Core/Math/Vector.h"
#include "Gameplay/Components/SpriteComponent.h"


Asteroid::Asteroid()
{
	m_Behavior = std::make_unique<SteeringBehavior>();
	m_Sprite = std::make_unique<SpriteComponent>();
}

Asteroid::Asteroid(int SpriteID, std::string Filename)
{
	m_Behavior = std::make_unique<SteeringBehavior>();
	m_Sprite = std::make_unique<SpriteComponent>(SpriteID, Filename);
}

Asteroid::~Asteroid()
{

}

void Asteroid::Initialize()
{

}

void Asteroid::Update(float DelaTime)
{
	Vec2 Steering;
	//Vec2 Acceleration = Steering / m_Mass;
}

void Asteroid::Render()
{

}
