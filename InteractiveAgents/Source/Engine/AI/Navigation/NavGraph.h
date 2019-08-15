#pragma once

class World;
struct NavNode;
struct NavPath;
struct NavLink;

#include <vmath.h>
#include <vector>

/**
 * A navigation graph that is used by AI controlled entities to navigate the world
 */
class NavGraph
{
public:
	/** Default NavGraph constructor */
	NavGraph(World* world);

	/** Default NavGraph destructor */
	~NavGraph();

	/** Returns a random node from the graph */
	NavNode* GetRandomNode();

	/** Create the navigation graph */
	void BuildGraph();

	/** Draws the navigation graph */
	void DrawGraph();

private:
	/** Links two nodes together by forming a navigation link between them */
	void LinkNodes(NavNode* firstNode, NavNode* secondNode);

private:
	/** List of all graph navigation nodes */
	std::vector<NavNode*> m_nodes;

	/** List of all graph navigation links */
	std::vector<NavLink*> m_links;

	/** Pointer to the world object */
	World* m_cachedWorld;
};