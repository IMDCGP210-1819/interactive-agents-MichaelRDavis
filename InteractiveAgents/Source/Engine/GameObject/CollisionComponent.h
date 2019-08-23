#pragma once

#include <Box2D/Box2D.h>

class CollisionComponent
{
public:
	CollisionComponent();
	~CollisionComponent();

	virtual void OnCollisionBegin();
	virtual void OnCollisionEnd();

private:
	b2Shape::Type m_shapeType;
	b2CircleShape m_circleCollision;
	b2Fixture* m_fixture;
};