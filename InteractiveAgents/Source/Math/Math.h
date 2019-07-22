#pragma once

#include <random>
#include <vmath.h>

class Random
{
public:
	Random() = default;
	~Random() = default;

	template<typename T>
	T GetRange(T min, T max)
	{
		std::uniform_real_distribution<T> dist(min, max);
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