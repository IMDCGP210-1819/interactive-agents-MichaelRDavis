#pragma once

#include <vector>

struct NavNode;

struct NavPath
{
	NavPath()
	{

	}

	void AddNode(NavNode* node)
	{
		path.push_back(node);
	}

	inline std::vector<NavNode*> GetNavigationPath() const
	{
		return path;
	}

	std::vector<NavNode*> path;
};