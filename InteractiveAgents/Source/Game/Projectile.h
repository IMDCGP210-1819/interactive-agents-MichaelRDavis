#pragma once

#include "GameObject/Entity.h"

class Projectile : public Entity
{
public:
	Projectile(World* world);
	~Projectile();

	void ApplyDamage(Entity* damagedActor);

	void SetOwner(std::shared_ptr<Entity> owner);

	inline std::shared_ptr<Entity> GetOwner() const
	{
		return m_owner;
	}

private:
	std::shared_ptr<Entity> m_owner;
	int32_t m_damage;
};