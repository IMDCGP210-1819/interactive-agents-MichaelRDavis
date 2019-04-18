#pragma once

class NavPath;

/**
 * Represents a single node in the navigation graph.
 * Contains a list of adjacent nodes.
 */
class NavNode
{
public:
	/** Default constructor. */
	NavNode();

	/** Default destructor. */
	~NavNode();

	/** Returns the adjacent list of nodes. */
	inline std::vector<NavNode*> GetNodeList() const
	{
		return m_NodeList;
	}

private:
	/** List of adjacent nodes. */
	std::vector<NavNode*> m_NodeList;
};