#pragma once

#include <vmath.h>
#include <vector>

#include "AI/Navigation/NavLink.h"

constexpr float DEFAULT_NODE_WEIGHT{ 5.0f };

struct NavNode
{
	NavNode(Vector2f inPosition, float inWeight = DEFAULT_NODE_WEIGHT)
	{
		position = inPosition;
		weight = inWeight;
	}

	Vector2f position;
	float weight;
	std::vector<NavLink*> links;

	void GetNeighbours(std::vector<NavNode*> outNeighbours)
	{
		for (auto it = links.begin(); it != links.end(); ++it)
		{
			NavLink* link = *it;
			outNeighbours.push_back(link->GetNeighbour(this));
		}
	}

	NavLink* GetLink(NavNode* linkedNode)
	{
		for (auto it = links.begin(); it != links.end(); ++it)
		{
			NavLink* link = *it;
			if (link->GetNeighbour(this) == linkedNode)
			{
				return link;
			}
		}
	}

	float CalculateCost(NavNode* node)
	{
		NavLink* link = GetLink(node);
		Vector2f diff = node->position - position;
		return weight * diff.length();
	}
};