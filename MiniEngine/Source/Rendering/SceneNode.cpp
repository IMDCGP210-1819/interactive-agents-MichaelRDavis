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

}
