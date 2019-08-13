#include "AStar.h"
#include "AI/Navigation/NavPathNode.h"
#include "AI/Navigation/NavNode.h"
#include "AI/Navigation/NavPath.h"

AStar::AStar()
{

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
		}
	}
}