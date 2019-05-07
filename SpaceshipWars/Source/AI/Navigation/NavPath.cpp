#include "stdafx.h"
#include "NavPath.h"

NavPath::NavPath()
	: m_index(m_path.end())
{

}

NavPath::~NavPath()
{

}

void NavPath::ResetNavPath()
{
	m_index = m_path.begin();
}

bool NavPath::CheckForNextNode(const Vec2& position)
{
	if (m_index == m_path.end())
	{
		return false;
	}

	Vec2 diff = position - (*m_index)->GetPosition();
	if (diff.Size() <= (*m_index)->GetWeight())
	{
		++m_index;
		return true;
	}

	return false;
}

bool NavPath::CheckForEnd()
{
	if (m_index == m_path.end())
	{
		return true;
	}

	return false;
}

void NavPath::AddNavNode(NavNode* inNode)
{
	assert(inNode != nullptr);
	m_path.push_front(inNode);
}
