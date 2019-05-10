#pragma once

class NavNode;
class NavNodeData;
class NavPath;

/**
 *	A* algorithm implemtation. 
 */
class AStar
{
public:
	/** Default constructor. */
	AStar();

	/** Default destructor. */
	~AStar();

	/** Destroys the navigation path found by this algorithm. */
	void Destroy();

	/** Searches the navigation graph for a navigation path.
	*	Returns the found navigation path.
	*/
	NavPath* Search(NavNode* startNode, NavNode* targetNode);

private:
	/** Start node */
	NavNode* m_startNode;

	/** Target node. */
	NavNode* m_targetNode;

	/** Nodes in the open set. */
	std::list<NavNodeData*> m_openSet;
};