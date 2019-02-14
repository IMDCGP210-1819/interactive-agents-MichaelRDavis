#include "MiniPCH.h"
#include "GraphEdge.h"

Engine::GraphEdge::GraphEdge()
	: m_From(0)
	, m_To(0)
	, m_Cost(1.0)
{

}

Engine::GraphEdge::~GraphEdge()
{

}

void Engine::GraphEdge::SetFrom(int NewIndex)
{
	m_From = NewIndex;
}

void Engine::GraphEdge::SetTo(int NewIndex)
{
	m_To = NewIndex;
}

void Engine::GraphEdge::SetCost(int NewCost)
{
	m_Cost = NewCost;
}

Engine::GraphEdge::GraphEdge(int From, int To, int Cost)
	: m_From(From)
	, m_To(To)
	, m_Cost(Cost)
{

}

Engine::GraphEdge::GraphEdge(int From, int To)
	: m_From(From)
	, m_To(To)
	, m_Cost(0.0)
{

}

