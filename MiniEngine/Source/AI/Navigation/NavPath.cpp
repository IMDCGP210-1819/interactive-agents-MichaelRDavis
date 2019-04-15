#include "MiniPCH.h"
#include "NavPath.h"

NavPath::NavPath()
	: m_From(0)
	, m_To(0)
	, m_Cost(1.0)
{

}

NavPath::~NavPath()
{

}

void NavPath::SetFrom(int NewIndex)
{
	m_From = NewIndex;
}

void NavPath::SetTo(int NewIndex)
{
	m_To = NewIndex;
}

void NavPath::SetCost(int NewCost)
{
	m_Cost = NewCost;
}

NavPath::NavPath(int From, int To, int Cost)
	: m_From(From)
	, m_To(To)
	, m_Cost(Cost)
{

}

NavPath::NavPath(int From, int To)
	: m_From(From)
	, m_To(To)
	, m_Cost(0.0)
{

}

