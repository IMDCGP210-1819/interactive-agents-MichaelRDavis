#pragma once

#include <map>
#include <vector>
#include "AI/Navigation/NavGraph.h"

class AStar
{
public:
	AStar();
	~AStar();

	void Search(NavNode* startNode, NavNode* goalNode);

private:
	NavNode* m_goalNode;
	NavNode* m_startNode;
	std::vector<NavPath> m_openSet;
	std::map<NavNode, NavNode> m_map;
};