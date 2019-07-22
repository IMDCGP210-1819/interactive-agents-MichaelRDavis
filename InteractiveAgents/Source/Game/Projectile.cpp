#include "Projectile.h"

Projectile::Projectile(World* world)
	: Entity(world)
{
	m_damage = 25;
}

Projectile::~Projectile()
{

}

void Projectile::SetOwner(std::shared_ptr<Entity> owner)
{
	m_owner = owner;
}

