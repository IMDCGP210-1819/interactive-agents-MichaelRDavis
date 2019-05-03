#include "stdafx.h"
#include "Projectile.h"

Projectile::Projectile(SDL_Renderer* renderer)
	: Entity(renderer)
{

}

Projectile::~Projectile()
{

}

void Projectile::Initialize()
{
	Entity::Initialize();
}

void Projectile::SetOwner(std::shared_ptr<Entity> NewOwner)
{
	m_Owner.swap(NewOwner);
}

