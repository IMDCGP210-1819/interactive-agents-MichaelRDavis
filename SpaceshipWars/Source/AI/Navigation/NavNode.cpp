#include "stdafx.h"
#include "NavNode.h"
#include "NavLink.h"

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

void NavNode::InsertNavLink(NavLink* inLink)
{
	m_linkList.push_back(inLink);
}

void NavNode::GetNearestNavLink(std::list<NavNode*>& inNodes)
{
	for (auto it : m_linkList)
	{
		NavLink* link = it;
		inNodes.push_back(link->GetNearestNavNode(this));
	}
}

float NavNode::GetNavCost(NavNode* inNode)
{
	NavLink* link = GetNavLink(inNode);
	Vec2 diff = inNode->GetPosition() - m_position;
	return link->GetWeight() * diff.Size();
}

NavLink* NavNode::GetNavLink(NavNode* inNode)
{
	for (auto it : m_linkList)
	{
		NavLink* link = it;
		if (link->GetNearestNavNode(this) == inNode)
		{
			return link;
		}
	}

	return nullptr;
}
