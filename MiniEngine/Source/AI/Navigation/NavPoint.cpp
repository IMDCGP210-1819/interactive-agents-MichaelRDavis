#include "MiniPCH.h"
#include "NavPoint.h"

NavPoint::NavPoint()
	: m_Index(0)
{

}

NavPoint::NavPoint(int Index)
	: m_Index(Index)
{

}

NavPoint::~NavPoint()
{

}

void NavPoint::SetIndex(int NewIndex)
{
	m_Index = NewIndex;
}

void NavPoint::SetPosition(Vec2 NewPosition)
{
	m_Position = NewPosition;
}
