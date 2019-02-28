#pragma once

namespace Engine
{
	class World;

	class GameInstance
	{
	public:
		GameInstance();
		~GameInstance();

		inline World* GetWorld() const { return m_World.get(); }

	private:
		std::unique_ptr<World> m_World;
	};
}