#pragma once

namespace Engine
{
	struct Vec2 : public sf::Vector2f
	{
	public:
		Vec2();
		Vec2(float x, float y);
		Vec2(const sf::Vector2f& vec);
		Vec2(const Vec2& vec);
	};
}