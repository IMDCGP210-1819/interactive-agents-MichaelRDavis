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
	return true;
}

void CollisionComponent::SetRadius(float NewRadius)
{
	m_Radius = NewRadius;
}

