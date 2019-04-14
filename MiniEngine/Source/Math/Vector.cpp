#include "MiniPCH.h"
#include "Vector.h"

Vec2::Vec2()
	: X(0.0f)
	, Y(0.0f)
{
	
}

float Vec2::Length() const
{
	return sqrt(X * X + Y * Y);
}

float Vec2::LengthSquared() const
{
	return (X * X + Y * Y);
}

void Vec2::Normlaize()
{
	float VecLength = Length();
	if (VecLength > std::numeric_limits<float>::epsilon())
	{
		X /= VecLength;
		Y /= VecLength;
	}
}

float Vec2::DotProduct(const Vec2 Vec)
{
	return X * Vec.X + Y * Vec.Y;
}

const Vec2& Vec2::operator/=(const Vec2& Vec)
{
	X /= Vec.X;
	Y /= Vec.Y;
	return *this;
}

bool Vec2::operator==(const Vec2& Vec) const
{
	return (X == Vec.X) && (Y == Vec.Y);
}

bool Vec2::operator!=(const Vec2& Vec) const
{
	return (X != Vec.X) || (Y != Vec.Y);
}

const Vec2& Vec2::operator+=(float Scale)
{
	X += Scale;
	Y += Scale;
	return *this;
}

const Vec2& Vec2::operator-=(float Scale)
{
	X -= Scale;
	Y -= Scale;
	return *this;
}

const Vec2& Vec2::operator/=(float Scale)
{
	X /= Scale;
	Y /= Scale;
	return *this;
}

const Vec2& Vec2::operator*=(float Scale)
{
	X *= Scale;
	Y *= Scale;
	return *this;
}

const Vec2& Vec2::operator*=(const Vec2& Vec)
{
	X *= Vec.X;
	Y *= Vec.Y;
	return *this;
}

const Vec2& Vec2::operator-=(const Vec2& Vec)
{
	X -= Vec.X;
	Y -= Vec.Y;
	return *this;
}

const Vec2& Vec2::operator+=(const Vec2& Vec)
{
	X += Vec.X;
	Y += Vec.Y;
	return *this;
}

Vec2 operator*(float Scale, const Vec2& Vec)
{
	Vec2 Result(Vec);
	Result *= Scale;
	return Result;
}

Vec2 operator*(const Vec2& Vec, float Scale)
{
	Vec2 Result(Vec);
	Result *= Scale;
	return Result;
}

Vec2 operator+(const Vec2& VecA, const Vec2& VecB)
{
	return Vec2(VecA.X + VecB.X, VecA.Y + VecB.Y);
}

Vec2 operator-(const Vec2& VecA, const Vec2& VecB)
{
	return Vec2(VecA.X - VecB.X, VecA.Y - VecB.Y);
}

Vec2 operator*(const Vec2& VecA, const Vec2& VecB)
{
	return Vec2(VecA.X * VecB.X, VecA.Y * VecB.Y);
}

Vec2 operator/(const Vec2& VecA, const Vec2& VecB)
{
	return Vec2(VecA.X / VecB.X, VecA.Y / VecB.Y);
}

Vec2::Vec2(float InX, float InY)
	: X(InX)
	, Y(InY)
{
	
}
