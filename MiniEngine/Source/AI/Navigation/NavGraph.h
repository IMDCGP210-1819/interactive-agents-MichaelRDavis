#pragma once

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
		assert(From < m_Points.size() && From >= 0 && m_Points[From].Index() != 0 && "Invalid 'From' Index");

		assert(To < m_Points.size() && To >= 0 && m_Points[To].Index() != 0 && "Invalid 'To' Index");

		for (auto Path : m_Paths)
		{
			if (Path->To() == To)
				return *Path;
		}

		//assert(0 && "Path does not exist.");
	}

	/** Returns a ref to an edge.
	*	@param From -
	*	@param To -
	*/
	EdgeType& GetEdge(int From, int To)
	{
		assert(From < m_Points.size() && From >= 0 && m_Points[From].Index() != 0 && "Invalid 'From' Index");

		assert(To < m_Points.size() && To >= 0 && m_Points[To].Index() != 0 && "Invalid 'To' Index");

		for (auto Path : m_Paths)
		{
			if (Path->To() == To)
				return *Path;
		}

		//assert(0 && "Path does not exist.");
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
		assert(Node < m_Points.size() && "Invalid Node Idex");


	}

	void AddEdge(EdgeType Edge)
	{
		assert((Edge.From() < m_NextPointIndex) && (Edge.To() < m_NextPointIndex) && "Invalid Node Index");

		if ((m_Points[Edge.To()].Index() != 0) && (m_Points[Edge.From()].Index() != 0))
		{

		}

		if (!m_IsDirectedGraph)
		{

		}
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

	/** Returns the number of paths in the navigation graph. */
	int NumEdges() const
	{
		int PathAmount = 0;
		for (auto Path : m_Paths)
		{
			PathAmount += Path->size();
		}

		return PathAmount;
	}

	/** Returns true if the graph is directed. */
	bool IsDirectedGraph() const
	{
		return m_IsDirectedGraph;
	}

	/** Returns true if the navigation graph is empty. */
	bool IsEmpty() const
	{
		return m_Points.empty();
	}

	/** Retunrs true if a given node is present in the graph. */
	bool IsNodePresent(int Index) const
	{

	}

	/** Returns true if a given path is present in the graph. */
	bool IsPathPresent(int FirstNodeIndex, int SecondNodeIndex) const
	{

	}

	/** Returns true if the path is not present in the navigation graph. */
	bool IsUniquePath(int From, int To)
	{
		for (auto Path : m_Paths)
		{
			if (Path->To() == To)
			{
				return false;
			}
		}

		return true;
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
