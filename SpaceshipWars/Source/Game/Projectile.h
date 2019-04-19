#pragma once

#include "Gameplay/GameObject/Entity.h"

class CollisionComponent;
class SpriteComponent;

/**
 * 
 */
class Projectile : public Entity
{
public:
	/** Default constructor. */
	Projectile();

	/** Default destructor. */
	~Projectile();

	/** Set the owner of this projectile to a new oner. 
	*	@param NewOwner - The projectiles new owner.
	*/
	void SetOwner(std::shared_ptr<Entity> NewOwner);

	/** Returns the owner of this projectile. */
	inline std::shared_ptr<Entity> GetOwner() const
	{
		return m_Owner;
	}

private:
	/** The projectiles collision component. */
	std::unique_ptr<CollisionComponent> m_CollisionComp;

	/** The projectiles sprite component. */
	std::unique_ptr<SpriteComponent> m_Sprite;

	/** The projectiles owner. */
	std::shared_ptr<Entity> m_Owner;

	/** Damage applied on collision. */
	int m_Damage;
};