#pragma once

class Random
{
public:
	float Rand()
	{
		return 1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1000.0f - 1.0f)));
	}
};