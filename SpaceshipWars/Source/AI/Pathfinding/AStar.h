#pragma once

class NavNode;
class NavNodeData;

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

private:
	/** Start node */
	NavNode* m_startNode;

	/** Target node. */
	NavNode* m_targetNode;

	/**  */
	std::list<NavNodeData*> m_openSet;
};