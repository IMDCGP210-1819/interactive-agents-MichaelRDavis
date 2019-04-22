#include "MiniPCH.h"
#include "SceneNode.h"

SceneNode::SceneNode()
{

}

SceneNode::~SceneNode()
{

}

void SceneNode::AddChildNode(std::unique_ptr<SceneNode> InSceneNode)
{
	InSceneNode->m_ParentNode.swap(InSceneNode);
	m_ChildNodes.push_back(std::move(InSceneNode));
}

std::shared_ptr<SceneNode> SceneNode::RemoveChildNode(const SceneNode& InSceneNode)
{
	auto Node = std::find_if(m_ChildNodes.begin(), m_ChildNodes.end(), [&](std::shared_ptr<SceneNode>& Ptr)-> bool {return Ptr.get() == &InSceneNode; });
	std::shared_ptr<SceneNode> Result = std::move(*Node);
	Result->m_ParentNode = nullptr;
	m_ChildNodes.erase(Node);
	return Result;
}

sf::Transform SceneNode::GetTransform() const
{
	sf::Transform Transform = sf::Transform::Identity;
	for (const SceneNode* Node = this; Node != nullptr; Node = Node->m_ParentNode.get())
	{
		Transform = Node->getTransform() * Transform;
	}

	return Transform;
}

void SceneNode::Draw(sf::RenderTarget& Target, sf::RenderStates States) const
{

}

void SceneNode::DrawCurrentNode(sf::RenderTarget& Target, sf::RenderStates States) const
{
	States.transform *= getTransform();

	Draw(Target, States);
	DrawChildNodes(Target, States);
}

void SceneNode::DrawChildNodes(sf::RenderTarget& Target, sf::RenderStates States) const
{
	for (auto Child : m_ChildNodes)
	{
		Child->draw(Target, States);
	}
}
