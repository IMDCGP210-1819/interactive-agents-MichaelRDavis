#pragma once

#include <Box2D/Box2D.h>
#include <vmath.h>
#include "Math/MathWrapper.h"

class RayCast
{
public:
	static void LineTrace(Vector2f startLocation, Vector2f endLocation, float rayLength)
	{
		b2RayCastInput input;
		input.p1 = MathWrapper::ConvertVector(startLocation);
	}
};