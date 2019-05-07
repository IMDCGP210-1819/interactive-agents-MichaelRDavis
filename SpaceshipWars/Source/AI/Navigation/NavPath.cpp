#include "stdafx.h"
#include "NavPath.h"

NavPath::NavPath()
	: m_weight(0.0f)
{

}

NavPath::NavPath(float weight)
	: m_weight(weight)
{

}

NavPath::~NavPath()
{

}

void NavPath::ConnectNodes(NavNode* nodeA, NavNode* nodeB)
{
	m_nodes[0] = nodeA;
	m_nodes[1] = nodeB;
}

NavNode* NavPath::GetNearestNavNode(NavNode* inNode)
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

