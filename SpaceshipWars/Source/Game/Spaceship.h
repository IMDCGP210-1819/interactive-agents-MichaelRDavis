#pragma once

#include "Gameplay/GameFramework/Sprite.h"

namespace Game
{
	class Spaceship : public Engine::Sprite
	{
	public:
		Spaceship();
		~Spaceship();

	private:
		int m_Health;
	};
}