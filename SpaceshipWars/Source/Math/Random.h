#pragma once

class Random
{
public:
	static float Rand()
	{
		return 1000.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1000.0f)));
	}
};