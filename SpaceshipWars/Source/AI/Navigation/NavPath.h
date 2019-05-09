#pragma once

#include "Math/Vector.h"
#include "NavNode.h"

class NavNode;

/**
 * 
 */
class NavPath
{
	friend class AStar;

public:
	/** Default constructor. */
	NavPath();

	/** Default destructor. */
	~NavPath();

	/** Reset the navigation path. */
	void ResetNavPath();

	/** Check for the next navigation node, return true if there is a navigation node. */
	bool CheckForNextNode(const Vec2& position);

	/** Check for the end of this navigation path. */
	bool CheckForEnd();
	
	/** Returns the position of the current navigation node. */
	inline const Vec2& GetCurrentNodePosition() const
	{
		assert(m_index != m_path.end());
		return (*m_index)->GetPosition();
	}

private:
	/** Add a navigation node to the navigation path. */
	void AddNavNode(NavNode* inNode);

private:
	/** List of navigation nodes that make up a navigation path. */
	std::list<NavNode*> m_path;

	/** Index used to iterate through the navigation path. */
	std::list<NavNode*>::iterator m_index;
};