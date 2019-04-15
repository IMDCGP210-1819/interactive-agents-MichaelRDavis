#pragma once

#include "Gameplay/ECS/Entity.h"
#include "AI/FSM/IState.h"

template<typename T>
class IState;

template<typename T>
class FiniteStateMachine;

class SpriteComponent;

/**
 * 
 */
class Spaceship : public Entity
{
public:
	/** Default constructor. */
	Spaceship();

	/** Default destructor. */
	~Spaceship();

	// Entity interface
	void Initialize() override;
	void Update(float DeltaTime) override;
	void Render() override;

private:
	/** Spaceship AI behavior. */
	std::unique_ptr<FiniteStateMachine<Spaceship>> m_FSM;

	/** Spaceship sprite component. */
	std::unique_ptr<SpriteComponent> m_Sprite;

	/** Current health of the spaceship. */
	int m_Health;

	/** Max health of the spaceship. */
	int m_MaxHealth;
};