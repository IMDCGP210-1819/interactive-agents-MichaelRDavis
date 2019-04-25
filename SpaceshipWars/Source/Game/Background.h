#pragma once

#include "Gameplay/GameObject/Entity.h"

class SpriteComponent;

class Background : public Entity
{
public:
	Background();

	~Background();

	virtual void Initialize() override;

private:
	std::unique_ptr<SpriteComponent> m_Sprite;
};