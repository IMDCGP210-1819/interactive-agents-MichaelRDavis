#include "MiniPCH.h"
#include "NavPoint.h"

Engine::NavPoint::NavPoint()
	: m_Index(0)
{

}

Engine::NavPoint::NavPoint(int Index)
	: m_Index(Index)
{

}

Engine::NavPoint::~NavPoint()
{

}

void Engine::NavPoint::SetIndex(int NewIndex)
{
	m_Index = NewIndex;
}

void Engine::NavPoint::SetPosition(Vec2 NewPosition)
{
	m_Position = NewPosition;
}
