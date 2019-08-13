#include "AStar.h"
#include "AI/Navigation/NavPathNode.h"
#include "AI/Navigation/NavNode.h"
#include "AI/Navigation/NavPath.h"

AStar::AStar()
{
	m_goalNode = nullptr;
	m_startNode = nullptr;
}

AStar::~AStar()
{

}

NavPath* AStar::Search(NavNode* startNode, NavNode* goalNode)
{
	m_startNode = startNode;
	m_goalNode = goalNode;

	while (!m_openSet.empty())
	{
		NavPathNode* path = m_openSet.front();
		if (path->pathNode == m_goalNode)
		{
			NavPath* newPath = new NavPath;
			NavPathNode* node = path;
			while (node)
			{
				newPath->AddNode(node->pathNode);
				node = node->prevNode;
			}

			return newPath;
		}

		m_openSet.front();
		path->isClosed = true;

		std::vector<NavNode*> neighbours;
		path->pathNode->GetNeighbours(neighbours);

		for (auto it = neighbours.begin(); it != neighbours.end(); ++it)
		{
			NavNode* node = *it;

			auto found = m_map.find(node);
			if (found != m_map.end() && found->second->isClosed)
			{
				continue;
			}

			float pathCost = path->goal + node->CalculateCost(path->pathNode);
			bool isBetterNavPath = false;

			NavPathNode* evaluatedNavPath = nullptr;
			if (found != m_map.end())
			{
				evaluatedNavPath = found->second;
			}

			if (!evaluatedNavPath)
			{
				evaluatedNavPath = AddToOpenSet(node, path);
			}
			else if (pathCost < evaluatedNavPath->goal)
			{
				isBetterNavPath = true;
			}

			if (isBetterNavPath)
			{
				evaluatedNavPath->prevNode = path;
				evaluatedNavPath->CalculateHeuristic();
				ReInsert(evaluatedNavPath);
			}
		}
	}

	return nullptr;
}

NavPathNode* AStar::AddToOpenSet(NavNode* node, NavPathNode* prevNode)
{
	auto it = m_map.find(node);
	NavPathNode* pathNode = nullptr;
	if (it == m_map.end())
	{
		pathNode = new NavPathNode(prevNode, node, m_goalNode);
	}

	return pathNode;
}

void AStar::Insert(NavPathNode* node)
{

}

void AStar::ReInsert(NavPathNode* node)
{

}
