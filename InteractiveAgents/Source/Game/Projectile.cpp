#include "Projectile.h"
#include "Spaceship.h"

Projectile::Projectile(World* world)
	: Entity(world)
{
	m_damage = 25;
}

Projectile::~Projectile()
{

}

void Projectile::ApplyDamage(Entity* damagedActor)
{
	if (damagedActor != nullptr)
	{
		Spaceship* ship = dynamic_cast<Spaceship*>(damagedActor);
		ship->TakeDamage(m_damage);
	}
}

void Projectile::SetOwner(std::shared_ptr<Entity> owner)
{
	m_owner = owner;
}

