#pragma once

class Random
{
public:
	static float Rand()
	{
		return rand() / RAND_MAX + 1.0f;
	}
};