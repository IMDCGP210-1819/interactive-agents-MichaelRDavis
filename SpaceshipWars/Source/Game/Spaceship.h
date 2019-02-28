#pragma once

#include "Gameplay/ECS/Entity.h"

namespace Game
{
	class Spaceship : public Engine::Entity
	{
	public:
		Spaceship();
		~Spaceship();

	private:
		int m_Health;
	};
}