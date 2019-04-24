#pragma once

#include "Gameplay/GameObject/Component.h"

/**
 * Collision component used to detect intersection between game entities.
 */
class CollisionComponent : public Component
{
public:
	/** Default constructor. */
	CollisionComponent();

	/** Default destructor. */
	~CollisionComponent();

	/** Returns true if intersecting. 
	*	@param OtherComp - Intersecting collision component.
	*/
	bool Intersect(const CollisionComponent& OtherComp);

	/** Set the radius to a new value. 
	*	@param NewRadius - Set radius value.
	*/
	void SetRadius(float NewRadius);

	/** Returns the radius of the collision component. */
	inline float GetRadius() const
	{
		return m_Radius;
	}

private:
	/** Collision component radius. */
	float m_Radius;
};