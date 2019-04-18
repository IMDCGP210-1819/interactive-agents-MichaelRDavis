#include "GamePCH.h"
#include "Projectile.h"

Projectile::Projectile()
{

}

Projectile::~Projectile()
{

}

void Projectile::SetOwner(std::shared_ptr<Entity> NewOwner)
{
	m_Owner.swap(NewOwner);
}

