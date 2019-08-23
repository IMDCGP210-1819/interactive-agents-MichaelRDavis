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

	virtual void SetOwner(T* newOwner)
	{
		m_owner = newOwner;
	}

	inline std::shared_ptr<State<T>> GetActiveState() const
	{
		return m_activeState;
	}

protected:
	std::list<std::shared_ptr<State<T>>> m_states;
	T* m_owner;
	std::shared_ptr<State<T>> m_initialState;
	std::shared_ptr<State<T>> m_activeState;
};