#pragma once

namespace Engine
{
	class SceneNode
	{
	public:
		SceneNode();
		~SceneNode();

		void AddChildNode(std::unique_ptr<SceneNode> InSceneNode);
		std::unique_ptr<SceneNode> RemoveChildNode(const SceneNode& InSceneNode);

	private:
		std::vector<std::unique_ptr<SceneNode>> m_ChildNodes;
		std::unique_ptr<SceneNode> m_ParentNode;
	};
}