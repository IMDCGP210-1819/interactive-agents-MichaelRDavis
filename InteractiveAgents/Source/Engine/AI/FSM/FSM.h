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

protected:
	std::list<std::shared_ptr<State<T>>> m_states;
	std::shared_ptr<T> m_owner;
	std::shared_ptr<State<T>> m_initialState;
	std::shared_ptr<State<T>> m_activeState;
};