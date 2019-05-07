#include "stdafx.h"
#include "NavLink.h"

NavLink::NavLink()
	: m_weight(0.0f)
{

}

NavLink::NavLink(float weight)
	: m_weight(weight)
{

}

NavLink::~NavLink()
{

}

void NavLink::ConnectNodes(NavNode* nodeA, NavNode* nodeB)
{
	m_nodes[0] = nodeA;
	m_nodes[1] = nodeB;
}

NavNode* NavLink::GetNearestNavNode(NavNode* inNode)
{
	if (m_nodes[0] == inNode)
	{
		return m_nodes[1];
	}
	else
	{
		return m_nodes[0];
	}
}

