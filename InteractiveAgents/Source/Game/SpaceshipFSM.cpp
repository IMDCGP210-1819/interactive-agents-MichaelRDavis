#include "SpaceshipFSM.h"
#include "AI/FSM/State.h"
#include "AI/FSM/Transition.h"
#include "SpaceshipStates.h"

SpaceshipFSM::SpaceshipFSM()
{
	m_attack = std::make_shared<Attack>();
	m_patrol = std::make_shared<Patrol>();
	m_states.push_back(m_attack);
	m_states.push_back(m_patrol);
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
			m_activeState = transition->GetNextState();
		}
		else
		{
			m_activeState->OnUpdate(m_owner);
		}
	}
}
