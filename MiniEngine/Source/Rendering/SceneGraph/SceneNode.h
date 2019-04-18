#pragma once

/**
 * 
 */
class SceneNode : public sf::Transformable, public sf::Drawable
{
public:
	/** Default constructor. */
	SceneNode();
	
	/** Default destructor. */
	~SceneNode();

	/** Add a scene node to the list of scene nodes. 
	*	@param InSceneNode - Scene node to add.
	*/
	void AddChildNode(std::unique_ptr<SceneNode> InSceneNode);

	/** Remove a scene node from the list of scene nodes. 
	*	@param InSceneNode - Scene node to remove.
	*/
	std::unique_ptr<SceneNode> RemoveChildNode(const SceneNode& InSceneNode);

	/** Returns the transform of the scene node. */
	sf::Transform GetTransform() const;

	/** Retunrs the position of the scene node. */
	inline sf::Vector2f GetPosition() const
	{
		return GetTransform() * sf::Vector2f();
	}

private:
	/** List of scene nodes. */
	std::vector<std::unique_ptr<SceneNode>> m_ChildNodes;

	/** Parent scene node. */
	std::unique_ptr<SceneNode> m_ParentNode;
};