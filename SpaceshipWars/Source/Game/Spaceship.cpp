#include "GamePCH.h"
#include "Spaceship.h"
#include "AI/FSM/FiniteStateMachine.h"
#include "Gameplay/GameFramework/Sprite.h"

Spaceship::Spaceship()
{
	m_FSM = std::make_unique<FiniteStateMachine<Spaceship>>(this);
	m_Sprite = std::make_unique<SpriteComponent>();
}

Spaceship::~Spaceship()
{

}

void Spaceship::Initialize()
{

}

void Spaceship::Update(float DeltaTime)
{

}

void Spaceship::Render()
{

}
