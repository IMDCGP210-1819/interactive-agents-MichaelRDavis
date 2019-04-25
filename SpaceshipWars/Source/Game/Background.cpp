#include "GamePCH.h"
#include "Background.h"
#include "Gameplay/Components/SpriteComponent.h"
#include "Gameplay/World/World.h"

Background::Background()
{
	m_Sprite = std::make_unique<SpriteComponent>();
}

Background::~Background()
{

}

void Background::Initialize()
{
	Entity::Initialize();

	std::cout << "Background Created" << std::endl;

	m_World->AttachEntity(this);
}
