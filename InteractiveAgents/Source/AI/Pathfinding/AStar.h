#pragma once

#include <map>
#include <vector>

struct NavPath;
struct NavNode;
struct NavPathNode;

class AStar
{
public:
	AStar();
	~AStar();

	NavPath* Search(NavNode* startNode, NavNode* goalNode);

private:
	NavPathNode* AddToOpenSet(NavNode* node, NavPathNode* prevNode);
	void Insert(NavPathNode* node);
	void ReInsert(NavPathNode* node);

private:
	NavNode* m_goalNode;
	NavNode* m_startNode;
	std::vector<NavPathNode*> m_openSet;
	std::map<NavNode*, NavPathNode*> m_map;
};