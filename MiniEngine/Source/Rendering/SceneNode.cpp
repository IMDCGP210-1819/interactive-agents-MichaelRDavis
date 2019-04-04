#include "MiniPCH.h"
#include "SceneNode.h"

Engine::SceneNode::SceneNode()
{

}

Engine::SceneNode::~SceneNode()
{

}

void Engine::SceneNode::AddChildNode(std::unique_ptr<SceneNode> InSceneNode)
{
	InSceneNode->m_ParentNode.swap(InSceneNode);
	m_ChildNodes.push_back(std::move(InSceneNode));
}

std::unique_ptr<Engine::SceneNode> Engine::SceneNode::RemoveChildNode(const SceneNode& InSceneNode)
{
	auto Node = std::find_if(m_ChildNodes.begin(), m_ChildNodes.end(), [&](std::unique_ptr<SceneNode>& Ptr)-> bool {return Ptr.get() == &InSceneNode; });
	std::unique_ptr<SceneNode> Result = std::move(*Node);
	Result->m_ParentNode = nullptr;
	m_ChildNodes.erase(Node);
	return Result;
}
