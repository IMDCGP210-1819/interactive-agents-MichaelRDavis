#include "GamePCH.h"
#include "Asteroid.h"
#include "Math/Vector.h"
#include "Gameplay/GameFramework/Sprite.h"


Asteroid::Asteroid()
{
	m_Behavior = std::make_unique<SteeringBehavior>();
	m_Sprite = std::make_unique<SpriteComponent>();
}

Asteroid::~Asteroid()
{

}

void Asteroid::Update(float DelaTime)
{
	Vec2 Steering;
	//Vec2 Acceleration = Steering / m_Mass;
}
