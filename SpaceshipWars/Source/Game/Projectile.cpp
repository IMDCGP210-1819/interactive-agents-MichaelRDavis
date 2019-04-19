#include "GamePCH.h"
#include "Projectile.h"
#include "Gameplay/Components/CollisionComponent.h"
#include "Gameplay/Components/SpriteComponent.h"

Projectile::Projectile()
{
	m_CollisionComp = std::make_unique<CollisionComponent>();
	m_Sprite = std::make_unique<SpriteComponent>();
}

Projectile::~Projectile()
{

}

void Projectile::SetOwner(std::shared_ptr<Entity> NewOwner)
{
	m_Owner.swap(NewOwner);
}

