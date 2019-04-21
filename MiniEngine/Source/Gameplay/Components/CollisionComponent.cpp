#include "MiniPCH.h"
#include "CollisionComponent.h"

CollisionComponent::CollisionComponent()
{
	m_Radius = 0.0f;
}

CollisionComponent::~CollisionComponent()
{

}

bool CollisionComponent::Intersect(const CollisionComponent& OtherComp)
{

}

void CollisionComponent::SetRadius(float NewRadius)
{
	m_Radius = NewRadius;
}

const sf::Vector2f& CollisionComponent::GetComponentLocation() const
{

}

