#include "NavGraph.h"
#include "NavNode.h"
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
	return nullptr;
}

NavPath* NavGraph::FindPath(const Vector2f startPosition, const Vector2f endPosition)
{
	return nullptr;
}

void NavGraph::BuildGraph()
{
	for (int32_t x = -100.0f; x < 100.0f; x += 10.0f)
	{
		for (int32_t y = -100.0f; y < 100.0f; y += 10.0f)
		{

		}
	}
}

void NavGraph::DrawGraph()
{
	for (int32_t x = -100.0f; x < 100.0f; x += 10.0f)
	{
		for (int32_t y = -100.0f; y < 100.0f; y += 10.0f)
		{
			NavNode* node = new NavNode(Vector2f(x, y));
			m_nodes.push_back(node);
		}
	}
}
