#pragma once

struct Vec2
{
	Vec2();
	Vec2(float inX, float inY);
	Vec2(const Vec2& vec);

	friend Vec2 operator+(const Vec2& vecA, const Vec2& vecB);
	friend Vec2 operator-(const Vec2& vecA, const Vec2& vecB);
	friend Vec2 operator*(const Vec2& vecA, const Vec2& vecB);
	friend Vec2 operator/(const Vec2& vecA, const Vec2& vecB);

	friend Vec2 operator*(const Vec2& vec, float scalar);
	friend Vec2 operator*(float scalar, const Vec2& vec);

	Vec2 operator+=(const Vec2& vec);
	Vec2 operator-=(const Vec2& vec);
	Vec2 operator*=(const Vec2& vec);
	Vec2 operator/=(const Vec2& vec);

	Vec2 operator*=(float scalar);

	float x;
	float y;

	static const Vec2 zeroVector;
};
