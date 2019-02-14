#pragma once

namespace Engine
{
	template<class NodeType, class EdgeType>
	class SparseGraph
	{
	public:
		SparseGraph();
		SparseGraph(bool InIsDirectedGraph);
		~SparseGraph();

		const NodeType& GetNode(int Index) const;

		NodeType& GetNode(int Index);

	private:
		std::vector<NodeType> m_Nodes;
		std::vector<std::list<EdgeType>> m_Edges;
		bool m_IsDirectedGraph;
		int m_NextNodeIndex;
	};
}