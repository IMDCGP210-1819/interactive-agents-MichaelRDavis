#pragma once

namespace Engine
{
	class NavPoint
	{
	public:
		NavPoint();
		NavPoint(int Index);
		virtual ~NavPoint();

		__forceinline int GetIndex() const { return m_Index; }
		void SetIndex(int NewIndex);
		
	protected:
		int m_Index;
	};
}