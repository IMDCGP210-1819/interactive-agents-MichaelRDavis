#pragma once

#include <map>
#include <vector>

struct NavPath;
struct NavNode;
struct NavPathNode;

/**
 * 
 */
class AStar
{
public:
	/** Default AStar constructor */
	AStar();

	/** Default AStar destructor */
	~AStar();

	/** The A Star search algorithm, takes in a start node and a goal nodes has parameters */
	NavPath* Search(NavNode* startNode, NavNode* goalNode);

private:
	/**  */
	NavPathNode* AddToOpenSet(NavNode* node, NavPathNode* prevNode);

	/**  */
	void Insert(NavPathNode* node);

	/**  */
	void ReInsert(NavPathNode* node);

private:
	/** The goal node the algorithm needs to find */
	NavNode* m_goalNode;

	/** The start node to start searching from */
	NavNode* m_startNode;

	/**  */
	std::vector<NavPathNode*> m_openSet;

	/**  */
	std::map<NavNode*, NavPathNode*> m_map;
};