#pragma once

class NavNode;

class NavGraph
{
public:
	/** Default constructor. */
	NavGraph();

	/** Default destructor. */
	~NavGraph();

	/** Returns the list of navigation nodes for this navigation graph. */
	inline std::vector<NavNode*> GetNodeList() const
	{
		return m_NodeList;
	}

private:
	/** List of navigations nodes for this graph. */
	std::vector<NavNode*> m_NodeList;
};
