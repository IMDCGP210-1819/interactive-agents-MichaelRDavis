#pragma once

#include "Math/Vector.h"

namespace Engine
{
	class NavPoint
	{
	public:
		NavPoint();
		NavPoint(int Index);
		virtual ~NavPoint();

		inline int GetIndex() const { return m_Index; }
		void SetIndex(int NewIndex);

		inline Vec2 GetPosition() const { return m_Position; }
		void SetPosition(Vec2 NewPosition);

	protected:
		int m_Index;
		Vec2 m_Position;
	};
}