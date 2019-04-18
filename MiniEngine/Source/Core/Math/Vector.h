#pragma once

struct Vec2 : public sf::Vector2f
{
public:
	/** Length of the vector. */
	static float Size(const sf::Vector2f& Vec);

	/** Length squared of the vector. */
	static float SizeSquared(const sf::Vector2f& Vec);
	
	/** Normalize the vector. */
	static sf::Vector2f Normlaize(const sf::Vector2f& Vec);

	/** Calculate the dot product of the vector. */
	static float DotProduct(const sf::Vector2f VecA, const sf::Vector2f VecB);

	static sf::Vector2f Zerovector;
};
