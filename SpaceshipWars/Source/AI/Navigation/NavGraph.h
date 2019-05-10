#pragma once

class NavNode;
class NavLink;

#include "Math/Vector.h"

/**
 * Navigation system used by game entities to navigate the game world.
 */
class NavGraph
{
public:
	/** Default constructor. */
	NavGraph();

	/** Default destructor. */
	~NavGraph();

	/** Destroy the entire graph, called on object destruction. */
	void Destroy();

	/** Returns the closest node. */
	NavNode* FindClosesetNode(const Vec2& position);

private:
	/** List of navigations nodes for this graph. */
	std::vector<NavNode*> m_nodeList;

	/** List of navigation links for this graph. */
	std::list<NavLink*> m_linkList;
};
