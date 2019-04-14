#pragma once

template<class Type>
class IState
{
public:
	IState() {}
	virtual ~IState() {}

	virtual void OnEnter() {}
	virtual void OnExecute() {}
	virtual void OnExit() {}
};
