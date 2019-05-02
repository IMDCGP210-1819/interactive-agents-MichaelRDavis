#pragma once

class NavNode;

/**
 * A navigation grid is a 2D array of navigation nodes.
 * AI driven entities can use the navigation grid to find a navigation path.
 */
class NavGrid
{
public:
	/** Default constructor. */
	NavGrid();

	/** Default destructor. */
	~NavGrid();

	/** Initializes the navigation grid. */
	void CreateNavGrid();

	/** Find a navigation path using A*. */
	bool FindNavigationPath(NavNode* startNode, NavNode* endNode);

private:
	/** 2D array of navigation node. */
	std::vector<std::vector<NavNode*>> m_nodes;

	/** Number of navigation nodes in the x axis. */
	const size_t m_xNodes = 10;

	/** Number of navigation nodes in the y axis. */
	const size_t m_yNodes = 10;
};