#pragma once

#include <vmath.h>
#include <Box2D/Box2D.h>

class MathWrapper
{
public:
	static b2Vec2 ConvertVector(Vector2f inVector)
	{
		b2Vec2 newVector(inVector.x, inVector.y);
		return newVector;
	}
};