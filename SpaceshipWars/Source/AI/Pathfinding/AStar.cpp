#include "stdafx.h"
#include "AStar.h"
#include "AI/Navigation/NavNode.h"
#include "AI/Navigation/NavLink.h"

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
	return true;
}
