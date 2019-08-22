#pragma once

#include <list>
#include <memory>

template<class T>
class Transition;

template<class T>
class State
{
public:
	State() = default;
	virtual ~State() = default;

	virtual void OnEnter(std::shared_ptr<T> owner) = 0;
	virtual void OnUpdate(std::shared_ptr<T> owner) = 0;
	virtual void OnExit(std::shared_ptr<T> owner) = 0;

	inline void AddTransition(std::shared_ptr<Transition<T>> transition)
	{
		m_transitions.push_back(transition);
	}

	inline std::list<std::shared_ptr<Transition<T>>> GetTransitions() const
	{
		return m_transitions;
	}

protected:
	std::list<std::shared_ptr<Transition<T>>> m_transitions;
};