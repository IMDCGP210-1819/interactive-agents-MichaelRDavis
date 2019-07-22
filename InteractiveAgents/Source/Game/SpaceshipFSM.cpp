#include "SpaceshipFSM.h"
#include "AI/FSM/State.h"
#include "AI/FSM/Transition.h"

SpaceshipFSM::SpaceshipFSM()
{

}

SpaceshipFSM::~SpaceshipFSM()
{

}

void SpaceshipFSM::Update()
{
	for (auto state : m_activeState->GetTransitions())
	{

	}
}
