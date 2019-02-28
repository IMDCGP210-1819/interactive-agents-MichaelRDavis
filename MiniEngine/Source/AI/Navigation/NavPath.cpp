#include "MiniPCH.h"
#include "NavPath.h"

Engine::NavPath::NavPath()
	: m_From(0)
	, m_To(0)
	, m_Cost(1.0)
{

}

Engine::NavPath::~NavPath()
{

}

void Engine::NavPath::SetFrom(int NewIndex)
{
	m_From = NewIndex;
}

void Engine::NavPath::SetTo(int NewIndex)
{
	m_To = NewIndex;
}

void Engine::NavPath::SetCost(int NewCost)
{
	m_Cost = NewCost;
}

Engine::NavPath::NavPath(int From, int To, int Cost)
	: m_From(From)
	, m_To(To)
	, m_Cost(Cost)
{

}

Engine::NavPath::NavPath(int From, int To)
	: m_From(From)
	, m_To(To)
	, m_Cost(0.0)
{

}

