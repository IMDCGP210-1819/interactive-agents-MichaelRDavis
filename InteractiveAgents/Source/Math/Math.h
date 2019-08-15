#pragma once

#include <random>
#include <vmath.h>

class Random
{
public:
	Random() = default;
	~Random() = default;

	float GetRangef(float min, float max)
	{
		std::uniform_real_distribution<float> dist(min, max);
		return dist(m_mt);
	}

	int32_t GetRangei(int32_t min, int32_t max)
	{
		std::uniform_int_distribution<int32_t> dist(min, max);
		return dist(m_mt);
	}

private:
	std::mt19937 m_mt;
};

class VectorUtilities
{
public:
	static Vector2f Turncate(Vector2f vec, float scale)
	{
		if (vec.length() > scale)
		{
			vec.normalize();
			return vec *= scale;
		}

		return Vector2f(0.0f, 0.0f);
	}
};