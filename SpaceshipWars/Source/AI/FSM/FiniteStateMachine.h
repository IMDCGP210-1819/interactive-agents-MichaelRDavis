#pragma once

#include "AI/FSM/IState.h"

/**
 *   
 */
template<class Type>
class TFiniteStateMachine
{
public:
	/** Default constructor. */
	TFiniteStateMachine()
		: m_Owner(nullptr)
	{

	}

	/** Initialize the owner of this state machine. 
	*	@param Owner - Template owner to initialize.
	*/
	TFiniteStateMachine(Type* Owner)
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

	void ChangeState(std::shared_ptr<IState<Type>> NewState)
	{
		m_PreviousState = std::make_shared<IState<Type>>().swap(m_CurrentState);
		m_CurrentState->OnExit(m_Owner);
		m_CurrentState = std::make_shared<IState<Type>>().swap(NewState);
		m_CurrentState->OnEnter(m_Owner);
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
	Type* m_Owner;
	std::shared_ptr<IState<Type>> m_State;
	std::shared_ptr<IState<Type>> m_CurrentState;
	std::shared_ptr<IState<Type>> m_PreviousState;
};
