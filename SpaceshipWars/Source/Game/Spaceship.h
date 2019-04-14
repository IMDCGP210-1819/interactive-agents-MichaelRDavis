#pragma once

#include "Gameplay/GameFramework/Sprite.h"
#include "AI/FSM/IState.h"

template<typename T>
class IState;

class SpaceshipFSM;

class Spaceship : public Sprite
{
public:
	Spaceship();
	~Spaceship();

	void Initialize() override;
	void Update(float DeltaTime) override;
	void Render() override;

private:
	//std::unique_ptr<SpaceshipFSM> m_FSM;

	IState<Spaceship> m_CurrentState;
	IState<Spaceship> m_PreviouState;

	int m_Health;
};