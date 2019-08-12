#pragma once

#include <vmath.h>
#include <vector>

struct NavLink;

struct NavNode
{
	Vector2f position;
	float weight;
	std::vector<NavLink> links;
};

struct NavLink
{
	float weight;
	NavNode* to;
	NavNode* from;
};

struct NavPath
{
	NavLink* link;
	bool closed;
	float heuristic;
	float fitness;
};

class NavGraph
{
public:
	NavGraph();
	~NavGraph();

	void BuildGraph();
};