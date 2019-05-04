#include "stdafx.h"
#include "Vector.h"

const Vec2 Vec2::zeroVector;

Vec2::Vec2()
{
	x = 0.0f;
	y = 0.0f;
}

Vec2::Vec2(float inX, float inY)
{
	x = inX;
	y = inY;
}

Vec2::Vec2(const Vec2& vec)
{
	Vec2(vec.x, vec.y);
}

float Vec2::SizeSquared() const
{
	return (x * x + y * y);
}

float Vec2::Size() const
{
	return sqrtf(SizeSquared());
}

void Vec2::Normalize()
{
	float Length = Size();
	x /= Length;
	y /= Length;
}

Vec2 operator+(const Vec2& vecA, const Vec2& vecB)
{
	return Vec2(vecA.x + vecB.x, vecA.y + vecB.y);
}

Vec2 operator-(const Vec2& vecA, const Vec2& vecB)
{
	return Vec2(vecA.x - vecB.x, vecA.y - vecB.y);
}

Vec2 operator*(const Vec2& vecA, const Vec2& vecB)
{
	return Vec2(vecA.x * vecB.x, vecA.y * vecB.y);
}

Vec2 operator/(const Vec2& vecA, const Vec2& vecB)
{
	return Vec2(vecA.x / vecB.x, vecA.y / vecB.y);
}

Vec2 operator*(const Vec2& vec, float scalar)
{
	return Vec2(vec.x * scalar, vec.y * scalar);
}

Vec2 operator*(float scalar, const Vec2& vec)
{
	return Vec2(vec.x * scalar, vec.y * scalar);
}

Vec2 Vec2::operator+=(const Vec2& vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}

Vec2 Vec2::operator-=(const Vec2& vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}

Vec2 Vec2::operator*=(const Vec2& vec)
{
	x *= vec.x;
	y *= vec.y;
	return *this;
}

Vec2 Vec2::operator/=(const Vec2& vec)
{
	x /= vec.x;
	y /= vec.y;
	return *this;
}

Vec2 Vec2::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}
