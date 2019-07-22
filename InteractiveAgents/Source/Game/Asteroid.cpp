#include "Asteroid.h"
#include "AI/Steering/Steering.h"
#include "Math/Math.h"

Asteroid::Asteroid(World* world)
	: Entity(world)
{
	m_behavior = std::make_unique<Steering>();
	m_behavior->SetOwner(this);
}

Asteroid::~Asteroid()
{

}

void Asteroid::Update(float deltaTime)
{
	Entity::Update(deltaTime);

	Vector2f force = m_behavior->Wander(deltaTime);
	force = force / m_mass;
	m_velocity += force * deltaTime;
	m_velocity = VectorUtilities::Turncate(m_velocity, m_speed);
	m_position += m_velocity * deltaTime;
	Constrain(m_position, 1920, 1080);
}

void Asteroid::Draw()
{
	Entity::Draw();
}

void Asteroid::ApplyDamage(int32_t damage, Entity* otherEntity /*= nullptr*/)
{

}
