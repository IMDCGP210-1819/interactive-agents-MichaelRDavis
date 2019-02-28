#pragma once

namespace Engine
{
	template<class NodeType, class EdgeType>
	class NavGraph
	{
	public:
		/** Default NavGraph constructor. */
		NavGraph()
		{

		}

		/** Constructor with args.
		*	@param InIsDirectedGraph - Set navigation graph to a directed graph.
		*/
		NavGraph(bool InIsDirectedGraph)
			: m_IsDirectedGraph(InIsDirectedGraph)
			, m_NextPointIndex(0)
		{

		}

		/** Default NavGraph destructor. */
		~NavGraph()
		{

		}

		/** Returns a const ref to a node at a given index. 
		*	@param Index - Index of the node.
		*/
		const NodeType& GetNode(int Index) const
		{
			assert(Index < m_Points.size() && Index >= 0 && "Invalid Index");
			return m_Points[Index];
		}

		/** Returns a ref to a node at given index.
		*	@param Index - Index of the node.
		*/
		NodeType& GetNode(int Index)
		{
			assert(Index < m_Points.size() && Index >= 0 && "Invalid Index");
			return m_Points[Index];
		}

		/** Returns a const ref to an edge. 
		*	@param From - 
		*	@param To - 
		*/
		const EdgeType& GetEdge(int From, int To) const
		{
			for (auto Path : m_Paths)
			{
				
			}
		}

		/** Returns a ref to an edge.
		*	@param From -
		*	@param To - 
		*/
		EdgeType& GetEdge(int From, int To)
		{

		}

		/** Retunrs the next point index. */
		int GetNextPointIndex() const
		{
			return m_NextPointIndex;
		}

		/** Clears the navigation graph. */
		void Clear()
		{
			m_NextPointIndex = 0;
			m_Points.clear();
			m_Paths.clear();
		}

		/** Add a point to the navigation graph. Returns the index of the node.
		*	@param Node - Node to add into the graph.
		*/
		int AddNode(NodeType Node)
		{

		}

		/** Remove a point from the navigation graph. 
		*	@param 
		*/
		void RemoveNode(int Node)
		{

		}

		void AddEdge(EdgeType Edge)
		{

		}

		void RemoveEdge(int From, int To)
		{
			for (auto Paths : m_Paths)
			{
				Paths.clear();
			}
		}

		int NumNodes() const
		{

		}

		int NumActiveNodes() const
		{

		}

		int NumEdges() const
		{
			
		}

		bool IsDirectedGraph() const
		{

		}

		bool IsEmpty() const
		{

		}

		bool IsPresent(int Index) const
		{

		}

	private:
		/** List of points that make up this navigation graph. */
		std::vector<NodeType> m_Points;

		/** List of paths that connect points to each other. */
		std::vector<std::list<EdgeType>> m_Paths;

		/** Is this navigation graph a directed graph. */
		bool m_IsDirectedGraph;

		/** Index of the next point to be added. */
		int m_NextPointIndex;
	};
}