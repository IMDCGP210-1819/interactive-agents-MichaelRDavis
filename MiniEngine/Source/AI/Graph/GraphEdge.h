#pragma once

namespace Engine
{
	class GraphEdge
	{
	public:
		GraphEdge();
		GraphEdge(int From, int To);
		GraphEdge(int From, int To, int Cost);
		virtual ~GraphEdge();

		void SetFrom(int NewIndex);
		void SetTo(int NewIndex);
		void SetCost(int NewCost);

		__forceinline int GetFrom() const { return m_From; }
		__forceinline int GetTo() const { return m_To; }
		__forceinline double GetCost() { return m_Cost; }

	protected:
		int m_From;
		int m_To;
		double m_Cost;
	};
}