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

	/**  */
	NavNode* m_pathNode;

	/** Pointer to the target node. */
	NavNode* m_targetNode;
};