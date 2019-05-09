#pragma once

#include "AI/FSM/IState.h"

/**
 * A generic finite state machine implementation.  
 */
template<class T>
class TFiniteStateMachine
{
public:
	/** Default constructor. */
	TFiniteStateMachine()
		: m_Owner(nullptr)
	{

	}

	/** Initialize the owner of this state machine. */
	TFiniteStateMachine(T* Owner)
		: m_Owner(Owner)
	{

	}

	/** Default constructor. */
	~TFiniteStateMachine()
	{

	}

	/** Update the state machine, called every frame. */
	void OnUpdate()
	{
		if (m_State)
		{
			m_State->OnExecute(m_Owner);
		}

		if (m_CurrentState)
		{
			m_CurrentState->OnExecute(m_Owner);
		}
	}

	/** Switch to a new state. */
	void ChangeState(std::shared_ptr<IState<T>> NewState)
	{
		m_PreviousState = std::make_shared<IState<T>>().swap(m_CurrentState);
		m_CurrentState->OnExit(m_Owner);
		m_CurrentState = std::make_shared<IState<T>>().swap(NewState);
		m_CurrentState->OnEnter(m_Owner);
	}

	/** Switch to the previous state. */
	void RevertToPreviousState()
	{
		ChangeState(m_PreviousState);
	}

	/** Set the global state. */
	void SetState(std::shared_ptr<IState<T>> NewState)
	{
		m_State = std::make_shared<IState<T>>().swap(NewState);
	}

	/** Set the current state. */
	void SetCurrentState(std::shared_ptr<IState<T>> NewState)
	{
		m_CurrentState = std::make_shared<IState<T>>().swap(NewState);
	}

	/** Set the previous state. */
	void SetPreviousState(std::shared_ptr<IState<T>> NewState)
	{
		m_PreviousState = std::make_shared<IState<T>>().swap(NewState);
	}

private:
	/** The owner of this state machine. */
	T* m_Owner;

	/** The global state of the state machine. */
	std::shared_ptr<IState<T>> m_State;

	/** The current state of the state machine. */
	std::shared_ptr<IState<T>> m_CurrentState;

	/** The previous state of the state machine. */
	std::shared_ptr<IState<T>> m_PreviousState;
};
