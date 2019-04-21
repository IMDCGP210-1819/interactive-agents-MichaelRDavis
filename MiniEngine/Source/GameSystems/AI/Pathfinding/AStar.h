#pragma once

class NavPath;
class NavNode;
class NavGraph;

/**
 * 
 */
struct AStarData
{
	/** Default constructor. */
	AStarData()
	{
		ParentPath = nullptr;
		Heuristic = 0.0f;
		IsOpenSet = false;
		IsClosedSet = false;
	}

	/**  */
	const NavPath* ParentPath;

	/**  */
	float Heuristic;

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

private:
	/**  */
	std::unordered_map<const NavNode*, AStarData> m_AStarMap;
};