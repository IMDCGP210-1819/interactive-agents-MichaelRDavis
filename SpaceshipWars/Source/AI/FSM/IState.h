#pragma once

/**
 * Interface class for all state machine states.
 */
template<class T>
class IState
{
public:
	/** Default constructor. */
	IState() {}

	/** Default destructor. */
	virtual ~IState() {}

	/** Called on entry to this state. */
	virtual void OnEnter(T* Owner) {}

	/** Called when this state is updated, called once per frame. */
	virtual void OnExecute(T* Owner) {}

	/** Called when exiting this state. */
	virtual void OnExit(T* Owner) {}
};
