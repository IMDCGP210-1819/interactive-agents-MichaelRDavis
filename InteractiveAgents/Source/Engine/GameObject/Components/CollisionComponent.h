#pragma once

#include "GameObject/Component.h"
#include <Box2D/Box2D.h>

class CollisionComponent : public Component
{
public:
	/** Default constructor */
	CollisionComponent();

	/** Default destructor */
	~CollisionComponent();

protected:
	b2Shape::Type m_shapeType;
};