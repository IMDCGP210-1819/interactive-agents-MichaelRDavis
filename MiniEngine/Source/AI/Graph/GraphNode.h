#pragma once

namespace Engine
{
	class GraphNode
	{
	public:
		GraphNode();
		GraphNode(int Index);
		virtual ~GraphNode();

		__forceinline int GetIndex() const { return m_Index; }
		void SetIndex(int NewIndex);
		
	protected:
		int m_Index;
	};
}