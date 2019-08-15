#pragma once

#include <list>
#include <memory>

template<class T>
class State;

template<class T>
class FSM
{
public:
	FSM() = default;
	virtual ~FSM() = default;

	virtual void Update() = 0;

	virtual void SetActiveState(std::shared_ptr<State<T>> newState)
	{
		m_activeState = newState;
	}

	virtual void SetOwner(std::shared_ptr<T> newOwner)
	{
		m_owner = newOwner;
	}

protected:
	std::list<std::shared_ptr<State<T>>> m_states;
	std::shared_ptr<T> m_owner;
	std::shared_ptr<State<T>> m_initialState;
	std::shared_ptr<State<T>> m_activeState;
};