#include "MiniPCH.h"
#include "GraphNode.h"

Engine::GraphNode::GraphNode()
	: m_Index(0)
{

}

Engine::GraphNode::GraphNode(int Index)
	: m_Index(Index)
{

}

Engine::GraphNode::~GraphNode()
{

}

void Engine::GraphNode::SetIndex(int NewIndex)
{
	m_Index = NewIndex;
}
