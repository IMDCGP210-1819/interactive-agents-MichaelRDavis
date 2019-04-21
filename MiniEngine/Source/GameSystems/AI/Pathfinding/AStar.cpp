#include "MiniPCH.h"
#include "AStar.h"

AStar::AStar()
{

}

AStar::~AStar()
{

}

float AStar::CalculateHeuristic(const NavNode* StartNode, const NavNode* EndNode)
{
	return 0.0f;
}

bool AStar::Search(const NavGraph& Graph, const NavNode* StartNode, const NavNode* EndNode)
{
	std::vector<const NavNode*> OpenSet;
}
