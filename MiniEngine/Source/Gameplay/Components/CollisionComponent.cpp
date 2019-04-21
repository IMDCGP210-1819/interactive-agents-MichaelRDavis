#include "MiniPCH.h"
#include "CollisionComponent.h"
#include "Core/Math/Vector.h"
#include "Gameplay/GameObject/Entity.h"

CollisionComponent::CollisionComponent()
{
	m_Radius = 0.0f;
}

CollisionComponent::~CollisionComponent()
{

}

bool CollisionComponent::Intersect(const CollisionComponent& OtherComp)
{
	sf::Vector2f Diff = GetComponentLocation() - OtherComp.GetComponentLocation();
	float DistSq = Vec2::SizeSquared(Diff);

	float RadiusSq = GetRadius() + OtherComp.GetRadius();
	RadiusSq *= m_Radius;

	return DistSq <= RadiusSq;
}

void CollisionComponent::SetRadius(float NewRadius)
{
	m_Radius = NewRadius;
}

const sf::Vector2f& CollisionComponent::GetComponentLocation() const
{
	return m_Owner->GetPosition();
}

