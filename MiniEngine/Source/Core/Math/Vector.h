#pragma once

struct Vec2 : public sf::Vector2f
{
public:
	Vec2();
	Vec2(float InX, float InY);

	float Length() const;
	float LengthSquared() const;
	void Normlaize();
	float DotProduct(const Vec2 Vec);

	const Vec2& operator+=(const Vec2& Vec);
	const Vec2& operator-=(const Vec2& Vec);
	const Vec2& operator*=(const Vec2& Vec);
	const Vec2& operator/=(const Vec2& Vec);

	const Vec2& operator+=(float Scale);
	const Vec2& operator-=(float Scale);
	const Vec2& operator*=(float Scale);
	const Vec2& operator/=(float Scale);

	bool operator==(const Vec2& Vec) const;
	bool operator!=(const Vec2& Vec) const;

	friend Vec2 operator*(const Vec2& Vec, float Scale);
	friend Vec2 operator*(float Scale, const Vec2& Vec);

	friend Vec2 operator+(const Vec2& VecA, const Vec2& VecB);
	friend Vec2 operator-(const Vec2& VecA, const Vec2& VecB);
	friend Vec2 operator*(const Vec2& VecA, const Vec2& VecB);
	friend Vec2 operator/(const Vec2& VecA, const Vec2& VecB);

	float X;
	float Y;
};
