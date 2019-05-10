#pragma once

/**
 * Utility class for generating random values.
 */
class Random
{
public:
	/** Returns a randomly generated float value. */
	float Rand()
	{
		return 1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1000.0f - 1.0f)));
	}
};