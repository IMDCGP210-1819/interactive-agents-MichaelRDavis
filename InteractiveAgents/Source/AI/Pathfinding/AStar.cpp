#include "AStar.h"

AStar::AStar()
{

}

AStar::~AStar()
{

}

void AStar::Search(NavNode* startNode, NavNode* goalNode)
{
	while (!m_openSet.empty())
	{
		NavPath* current = m_openSet.front();
	}
}