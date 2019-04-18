#include "GamePCH.h"
#include "Asteroid.h"
#include "Core/Math/Vector.h"
#include "Gameplay/Components/SpriteComponent.h"


Asteroid::Asteroid()
{
	m_Behavior = std::make_unique<SteeringBehavior>();
	m_Sprite = std::make_unique<SpriteComponent>();
}

Asteroid::~Asteroid()
{

}

void Asteroid::Initialize()
{

}

void Asteroid::Update(float DelaTime)
{
	sf::Vector2f Steering = Vec2::Zerovector;
	sf::Vector2f Acceleration = Steering / m_Mass;
}

void Asteroid::Render()
{

}
