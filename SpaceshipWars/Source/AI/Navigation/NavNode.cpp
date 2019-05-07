#include "stdafx.h"
#include "NavNode.h"
#include "NavPath.h"

NavNode::NavNode()
	: m_position(Vec2::zeroVector)
	, m_weight(DEFAULT_NODE_WEIGHT)
{

}

NavNode::NavNode(const Vec2& postion, float weight)
	: m_position(postion)
	, m_weight(weight)
{

}

NavNode::~NavNode()
{

}

void NavNode::InsertNavPath(NavPath* inPath)
{
	m_pathList.push_back(inPath);
}

void NavNode::GetNearestNavPaths(std::list<NavPath*>& inPaths)
{
	for (auto it : m_pathList)
	{
		NavPath* path = it;
	}
}

float NavNode::GetNavCost(NavNode* inNode)
{
	NavPath* path = GetNavPath(inNode);
	Vec2 diff = inNode->GetPosition() - m_position;
	return path->GetWeight() * diff.Size();
}

NavPath* NavNode::GetNavPath(NavNode* inNode)
{
	for (auto it : m_pathList)
	{
		NavPath* path = it;
		return path;
	}

	return nullptr;
}
