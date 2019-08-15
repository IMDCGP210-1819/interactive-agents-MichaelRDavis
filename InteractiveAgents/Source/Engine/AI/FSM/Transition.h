#pragma once

#include <memory>

template<class T>
class State;

template<class T>
class Transition
{
public:
	Transition() = default;
	~Transition() = default;

	virtual bool IsValid() = 0;
	virtual std::shared_ptr<State<T>> GetNextState() = 0;
	virtual void OnTransition() = 0;
};