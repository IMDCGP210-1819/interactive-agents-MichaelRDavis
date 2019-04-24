#pragma once

#include "Gameplay/GameObject/Component.h"

/**
 * 
 */
class SpriteComponent : public Component
{
public:
	SpriteComponent();
	SpriteComponent(int SpriteID, std::string Filename);
	~SpriteComponent();

private:
};
