#pragma once

#include "Math/Vector.h"

class NavLink;

/** Default weighting for a navigation nodes. */
static constexpr float DEFAULT_NODE_WEIGHT{ 5.0f };

/**
 * Represents a single node in the navigation graph.
 * Contains a list of adjacent navigation links.
 */
class NavNode
{
public:
	/** Default constructor. */
	NavNode();

	/** Initializes a navigation node with a position and a weight. */
	explicit NavNode(const Vec2& postion, float weight = DEFAULT_NODE_WEIGHT);

	/** Default destructor. */
	~NavNode();

	/** Add a navigation link to the navigation link list. */
	void InsertNavLink(NavLink* inLink);

	/** Gets the nearest navigation link for this node. */
	void GetNearestNavLink(std::list<NavNode*>& inNodes);

	/** Returns the navigation cost from a given node. */
	float GetNavCost(NavNode* inNode);

	/** Returns the postion of this node in 2D space. */
	inline const Vec2& GetPosition() const
	{
		return m_position;
	}

	/** Returns the weight of this node. */
	inline float GetWeight() const
	{
		return m_weight;
	}

private:
	/** Returns a navigation link from a given node. */
	NavLink* GetNavLink(NavNode* inNode);

private:
	/** List of adjacent navigation links. */
	std::list<NavLink*> m_linkList;

	/** Location of the navigation node in 2D space. */
	Vec2 m_position;

	/** Weight of this navigation node. */
	float m_weight;
};