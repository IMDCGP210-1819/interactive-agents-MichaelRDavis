#pragma once

class NavPath;

/**
 * Represents a single node in the navigation graph.
 * Contains a list of adjacent navigation paths.
 */
class NavNode
{
public:
	/** Default constructor. */
	NavNode();

	/** Default destructor. */
	~NavNode();

	/** Returns the list of adjacent of navigation paths for this node. */
	inline std::vector<NavPath*> GetPathList() const
	{
		return m_NodeList;
	}

private:
	/** List of adjacent navigation paths. */
	std::vector<NavPath*> m_PathList;
};