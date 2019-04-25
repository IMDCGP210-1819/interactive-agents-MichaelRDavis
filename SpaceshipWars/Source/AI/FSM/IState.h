#pragma once

/**
 * 
 */
template<class Type>
class IState
{
public:
	/**  */
	IState() {}

	/**  */
	virtual ~IState() {}

	/**  */
	virtual void OnEnter(Type* Owner) {}

	/**  */
	virtual void OnExecute(Type* Owner) {}

	/**  */
	virtual void OnExit(Type* Owner) {}
};
