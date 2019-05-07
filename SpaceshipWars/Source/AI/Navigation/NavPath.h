#pragma once

class NavNode;

/** Default weighting for a navigation path. */
static constexpr float DEFAULT_PATH_WEIGHT{ 1.0f };

/**
 * Defines a navigation path connecting two nodes.
 */
class NavPath
{
public:
	/** Default constructor. */
	NavPath();

	/** Initializes a navigation path with a given weight. */
	explicit NavPath(float weight = DEFAULT_PATH_WEIGHT);

	/** Default destructor. */
	~NavPath();

	/** Joins two navigation nodes together. */
	void ConnectNodes(NavNode* nodeA, NavNode* nodeB);

	/** Returns the nearest navigation node. */
	NavNode* GetNearestNavNode(NavNode* inNode);

	/** Returns the weight of this navigation path. */
	inline float GetWeight() const
	{
		return m_weight;
	}

private:
	/** The weight for this navigation path. */
	float m_weight;

	/** A navigation path connects two nodes together. */
	NavNode* m_nodes[2];
};