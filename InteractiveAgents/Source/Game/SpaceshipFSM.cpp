#include "SpaceshipFSM.h"
#include "AI/FSM/State.h"
#include "AI/FSM/Transition.h"
#include "SpaceshipStates.h"
#include "SpaceshipTransitions.h"

SpaceshipFSM::SpaceshipFSM()
{
	m_attack = std::make_shared<Attack>();
	m_patrol = std::make_shared<Patrol>();
	m_foundEnemy = std::make_shared<FoundEnemy>(m_attack);
	m_foundPath = std::make_shared<FoundPath>(m_patrol);
	m_attack->AddTransition(m_foundPath);
	m_patrol->AddTransition(m_foundEnemy);
	m_states.push_back(m_attack);
	m_states.push_back(m_patrol);
	m_activeState = m_patrol;
}

SpaceshipFSM::~SpaceshipFSM()
{

}

void SpaceshipFSM::Update()
{
	for (auto transition : m_activeState->GetTransitions())
	{
		if (transition->IsValid())
		{
			m_activeState->OnExit(m_owner);
			m_activeState = transition->GetNextState();
			m_activeState->OnEnter(m_owner);
		}
		else
		{
			m_activeState->OnUpdate(m_owner);
		}
	}
}
