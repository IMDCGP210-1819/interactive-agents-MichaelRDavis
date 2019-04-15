#pragma once

#include "AI/Navigation/NavGraph.h"
#include <vector>


class NavPath;

/**
 *
 */
template<class T>
class AStar
{
public:
	/** Default constructor. */
	AStar()
	{

	}

	/** Constructor
	*	@param GraphType -
	*	@param Source -
	*	@param Target -
	*/
	AStar(T GraphType, int Source, int Target)
		: m_SearchPath(GraphType.NumNodes())
		, m_ShortestPath(GraphType.NumNodes())
	{

	}

	/** Default destructor. */
	~AStar()
	{

	}

	/** Retunrs a vector of paths that the algorithm has traveled. */
	inline std::vector<const NavPath*> GetSearchPath() const { return m_SearchPath; }

	/** Retunrs a vector of navigation point indexes that comprise the shortest path from the source to the target. */
	std::list<int> GetPathToTarget() const
	{
		std::list<int> Path;

		return Path;
	}

	/** Returns the travel cost to the navigation target. */
	inline double GetCostToTarget() const { return m_GCosts[m_Target]; }

private:
	/** A* search algorithm. */
	//void Search()
	//{
	//	// Create a priority queue of nodes. 
	//	std::priority_queue<float, int> Queue;

	//	// Add start navigation node to the queue.
	//	Queue.push(m_Source);

	//	// While the queue of nodes is not empty.
	//	while (!Queue.empty())
	//	{
	//		// Retrieve the lowest cost navigation node from the queue.
	//		int NextNode = Queue.pop();

	//		// Move the navigation node from the search path to the shortest path.
	//		m_ShortestPath[NextNode] = m_SearchPath[NextNode];

	//		// If the target navigation node has been found return.
	//		if (NextNode == m_Target)
	//		{
	//			return;
	//		}
	//	}
	//}

private:
	/** Const reference to the navigation graph. */
	const T& m_NavGraph;

	/**  */
	std::vector<double> m_GCosts;

	/**  */
	std::vector<double> m_FCosts;

	/**  */
	std::vector<const NavPath*> m_ShortestPath;

	/**  */
	std::vector<const NavPath*> m_SearchPath;

	/**  */
	int m_Source;

	/**  */
	int m_Target;
};