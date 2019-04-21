#pragma once

class NavPath;
class NavNode;
class NavGraph;

/**
 * Navigation node data
 */
struct AStarData
{
	/** Default constructor. */
	AStarData()
	{
		ParentPath = nullptr;
		Heuristic = 0.0f;
		Distance = 0.0f;
		IsOpenSet = false;
		IsClosedSet = false;
	}

	/** Pointer the parent path node. */
	const NavPath* ParentPath;

	/**  */
	float Heuristic;

	/** Distance from the actual start node. */
	float Distance;

	/** True if node is not already considered. */
	bool IsOpenSet;

	/** True if node is already considered. */
	bool IsClosedSet;
};

/**
 *
 */
class AStar
{
public:
	/** Default constructor. */
	AStar();

	/** Default destructor. */
	~AStar();

	/**  */
	float CalculateHeuristic(const NavNode* StartNode, const NavNode* EndNode);

	/** Searches a given graph for a path, returns true if a path is found. */
	bool Search(const NavGraph& Graph, const NavNode* StartNode, const NavNode* EndNode);
};