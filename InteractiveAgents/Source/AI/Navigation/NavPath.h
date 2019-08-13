#pragma once

#include <vector>

struct NavNode;

struct NavPath
{
	NavPath()
	{

	}

	std::vector<NavNode*> path;

	void AddNode(NavNode* node)
	{
		path.push_back(node);
	}
};