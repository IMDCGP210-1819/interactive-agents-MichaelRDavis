#include "MiniPCH.h"
#include "Vector.h"

float Vec2::Size(const sf::Vector2f& Vec)
{
	float Length = sqrt((Vec.x * Vec.x) + (Vec.y * Vec.y));
	return Length;
}

float Vec2::SizeSquared(const sf::Vector2f& Vec)
{
	return 0.0f;
}

sf::Vector2f Vec2::Normlaize(const sf::Vector2f& Vec)
{
	float Length = Size(Vec);
	if (Length != 0)
	{
		return sf::Vector2f(Vec.x / Length, Vec.y / Length);
	}

	return Vec;
}

float Vec2::DotProduct(const sf::Vector2f VecA, const sf::Vector2f VecB)
{
	return VecA.x * VecB.x + VecA.y * VecB.y;
}

sf::Vector2f Vec2::Zerovector(0.0f, 0.0f);
