#pragma once

#include "Engine.h"

class World;

/**
 * 
 */
class Game : public Engine
{
public:
	/** Default constructor. */
	Game();

	/** Default destructor. */
	virtual ~Game();

	/** Returns a pointer to the world object. */
	inline std::shared_ptr<World> GetWorld() const
	{
		return m_World;
	}

private:
	/** The world object. */
	std::shared_ptr<World> m_World;
};