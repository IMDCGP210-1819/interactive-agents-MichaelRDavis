#pragma once

namespace Engine
{
	template<class Type>
	class IState
	{
	public:
		IState() {}
		virtual ~IState() {}

		virtual void OnEnter() = 0;
		virtual void OnExecute() = 0;
		virtual void OnExit() = 0;
	};
}