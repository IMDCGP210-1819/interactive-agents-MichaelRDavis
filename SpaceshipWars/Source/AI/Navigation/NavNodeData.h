#pragma once
 
class NavNode;

/**
 * 
 */
class NavNodeData
{
public:
	/** Default constructor. */
	NavNodeData();

	/** Default destructor. */
	~NavNodeData();

private:
	/** The node that was last checked. */
	NavNodeData* m_previousNode;

	/** Pointer to the path node in the navigation graph. */
	NavNode* m_pathNode;

	/** Pointer to the target node. */
	NavNode* m_targetNode;

	/**  */
	float m_pathCost;

	/** Flag true if the node has been already considered for navigation. */
	bool m_isClosed;
};