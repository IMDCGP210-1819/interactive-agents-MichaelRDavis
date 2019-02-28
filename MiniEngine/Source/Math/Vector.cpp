#include "MiniPCH.h"
#include "Vector.h"

Engine::Vec2::Vec2()
{

}

Engine::Vec2::Vec2(const Vec2& vec)
{

}

Engine::Vec2::Vec2(const sf::Vector2f& vec)
{

}

Engine::Vec2::Vec2(float x, float y)
{
	sf::Vector2f(x, y);
}
