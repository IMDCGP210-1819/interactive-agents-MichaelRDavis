#pragma once

#include "Spaceship.h"

/**
 * The enemy spaceship
 */
class EnemySpaceship : public Spaceship
{
public:
	/** Default EnemySpaceship constructor */
	EnemySpaceship(World* world);

	/** Default EnemySpaceship constructor */
	~EnemySpaceship();
};