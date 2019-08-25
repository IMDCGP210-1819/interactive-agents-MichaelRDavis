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
	// If the goal start nodes are equal return null
	if (startNode == goalNode)
	{
		return nullptr;
	}

	m_startNode = startNode;
	m_goalNode = goalNode;

	// Add the start node to the open set
	AddToOpenSet(m_startNode, nullptr);

	// While the open set of navigation nodes to check is not empty
	while (!m_openSet.empty())
	{
		// Get the first navigation node in the open set
		NavPathNode* path = m_openSet.front();

		// If the first navigation node in the open set is the goal, then this is the navigation path
		if (path->pathNode == m_goalNode)
		{
			// Remake the navigation path and return the valid navigation path
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

NavPath* AStar::Find(NavNode* startNode, NavNode* goalNode)
{
	return Search(startNode, goalNode);
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
	assert(node);

	// If the open set is empty, add the node to the empty set
	if (m_openSet.empty())
	{
		m_openSet.push_back(node);
		return;
	}

	// Else, insert the the node into the open set via an insertion sort
	auto it = m_openSet.begin();
	NavPathNode* compareNode = *it;
	while (compareNode->fitness < node->fitness)
	{
		++it;
		if (it != m_openSet.end())
		{
			compareNode = *it;
		}
		else
		{
			break;
		}
	}

	m_openSet.insert(it, node);
}

void AStar::ReInsert(NavPathNode* node)
{
	for (auto it = m_openSet.begin(); it != m_openSet.end(); ++it)
	{
		if (node == *it)
		{
			m_openSet.erase(it);
			Insert(node);
			return;
		}
	}

	Insert(node);
}
