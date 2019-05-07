#pragma once

class NavNode;

/** Default weighting for a navigation path. */
static constexpr float DEFAULT_LINK_WEIGHT{ 1.0f };

/**
 * Defines a navigation link connecting two nodes.
 */
class NavLink
{
public:
	/** Default constructor. */
	NavLink();

	/** Initializes a navigation link with a given weight. */
	explicit NavLink(float weight = DEFAULT_LINK_WEIGHT);

	/** Default destructor. */
	~NavLink();

	/** Joins two navigation nodes together. */
	void ConnectNodes(NavNode* nodeA, NavNode* nodeB);

	/** Returns the nearest navigation node. */
	NavNode* GetNearestNavNode(NavNode* inNode);

	/** Returns the weight of this navigation link. */
	inline float GetWeight() const
	{
		return m_weight;
	}

private:
	/** The weight for this navigation link. */
	float m_weight;

	/** A navigation link connects two nodes together. */
	NavNode* m_nodes[2];
};