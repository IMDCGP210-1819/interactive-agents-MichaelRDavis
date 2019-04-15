#pragma once

class World;

class Game
{
public:
	Game();
	~Game();

	inline World* GetWorld() const { return m_World.get(); }

private:
	std::unique_ptr<World> m_World;
};
