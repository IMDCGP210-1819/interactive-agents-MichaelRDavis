#include "NavGraph.h"
#include "NavNode.h"
#include "Rendering/Drawing.h"
#include "GameObject/World.h"
#include "Math/Math.h"
#include <cstdint>

NavGraph::NavGraph(World* world)
	: m_cachedWorld(world)
{

}

NavGraph::~NavGraph()
{

}

NavNode* NavGraph::GetRandomNode()
{
	Random rand;
	uint32_t nodes = m_nodes.size();
	uint32_t node = rand.GetRangei(0, nodes);
	if (node <= nodes / 2)
	{
		auto it = m_nodes.begin();
		for (uint32_t i = 0; i < node; i++)
		{
			++it;
			return (*it);
		}
	}
	else
	{
		auto it = m_nodes.end();
		for (uint32_t i = 0; i >= node; i--)
		{
			--it;
			return (*it);
		}
	}
}

void NavGraph::BuildGraph()
{
	int32_t index = 0;
	for (int32_t x = -1000.0f; x < 1000.0f; x += 10.0f)
	{
		for (int32_t y = -1000.0f; y < 1000.0f; y += 10.0f)
		{
			NavNode* node = new NavNode(Vector2f(x, y));
			m_nodes.push_back(node);

			int32_t nodeIndex = index - 1;
			if (nodeIndex >= 0)
			{
				LinkNodes(m_nodes[nodeIndex], node);
			}

			nodeIndex = index - 9;
			if (nodeIndex >= 0)
			{
				LinkNodes(m_nodes[nodeIndex], node);
			}

			index++;
		}
	}
}

void NavGraph::DrawGraph()
{
	for (int32_t x = -1000.0f; x < 1000.0f; x += 10.0f)
	{
		for (int32_t y = -1000.0f; y < 1000.0f; y += 10.0f)
		{
			Drawing::DrawPoint(m_cachedWorld->GetRenderer(), x, y, Vector4f(1.0f, 1.0f, 1.0f, 1.0f));
		}
	}
}

void NavGraph::LinkNodes(NavNode* firstNode, NavNode* secondNode)
{
	NavLink* link = new NavLink();
	link->from = firstNode;
	link->to = secondNode;
	firstNode->links.push_back(link);
	secondNode->links.push_back(link);
	m_links.push_back(link);
}
