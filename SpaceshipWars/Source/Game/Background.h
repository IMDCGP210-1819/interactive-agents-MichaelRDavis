#pragma once

#include "GameObject/Entity.h"

class SpriteComponent;

class Background : public Entity
{
public:
	Background();

	~Background();

	virtual void Initialize() override;
};