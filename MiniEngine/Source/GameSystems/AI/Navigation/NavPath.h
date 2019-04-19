#pragma once

class NavNode;

/**
 * Defines a navigation path connecting to nodes.
 */
class NavPath
{
public:
	/** Default constructor. */
	NavPath();

	/** Default destructor. */
	virtual ~NavPath();

	/** Returns the from node. */
	inline NavNode* GetFromNode() const
	{
		return m_FromNode;
	}

	/** Returns the to node. */
	inline NavNode* GetToNode() const
	{
		return m_ToNode;
	}

	/** Returns the weight or travel cost of this path. */
	inline float GetWeight() const
	{
		return m_Weight;
	}

private:
	/** From node. */
	NavNode* m_FromNode;

	/** To node */
	NavNode* m_ToNode;

	/** The weight or travel cost for this path. */
	float m_Weight;
};