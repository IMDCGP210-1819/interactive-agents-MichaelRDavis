#pragma once

#include "AI/FSM/IState.h"

template<class Type>
class FiniteStateMachine
{
public:
	FiniteStateMachine(Type Owner)
		: m_Owner(Owner)
	{

	}

	~FiniteStateMachine()
	{

	}

	void OnUpdate()
	{
		if (m_State)
		{
			m_State->OnExecute();
		}

		if (m_CurrentState)
		{
			m_CurrentState->OnExecute();
		}
	}

	void ChangeState(std::shared_ptr<IState<Type>> NewState)
	{
		m_PreviousState = std::make_shared<IState<Type>>().swap(m_CurrentState);
		m_CurrentState->OnExit();
		m_CurrentState = std::make_shared<IState<Type>>().swap(NewState);
		m_CurrentState->OnEnter();
	}

	void RevertToPreviousState()
	{
		ChangeState(m_PreviousState);
	}

	void SetState(std::shared_ptr<IState<Type>> NewState)
	{
		m_State = std::make_shared<IState<Type>>().swap(NewState);
	}

	void SetCurrentState(std::shared_ptr<IState<Type>> NewState)
	{
		m_CurrentState = std::make_shared<IState<Type>>().swap(NewState);
	}

	void SetPreviousState(std::shared_ptr<IState<Type>> NewState)
	{
		m_PreviousState = std::make_shared<IState<Type>>().swap(NewState);
	}

private:
	std::shared_ptr<Type> m_Owner;
	std::shared_ptr<IState<Type>> m_State;
	std::shared_ptr<IState<Type>> m_CurrentState;
	std::shared_ptr<IState<Type>> m_PreviousState;
};
