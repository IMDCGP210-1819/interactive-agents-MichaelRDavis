#pragma once

#include <memory>

template<class T>
class State;

template<class T>
class Transition
{
public:
	Transition(std::shared_ptr<State<T>> state)
	{

	}

	~Transition() = default;

	virtual bool IsValid(std::shared_ptr<T> owner) = 0;
	virtual std::shared_ptr<State<T>> GetNextState() = 0;
	virtual void OnTransition() = 0;

protected:
	std::shared_ptr<State<T>> m_nextState;
};