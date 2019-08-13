#pragma once

struct NavNode;

constexpr float DEFAULT_LINK_WEIGHT{ 1.0f };

struct NavLink
{
	NavLink(float inWeight = DEFAULT_LINK_WEIGHT)
	{
		weight = inWeight;
		to = nullptr;
		from = nullptr;
	}

	NavNode* GetNeighbour(NavNode* node)
	{
		if (to == node)
		{
			return from;
		}
		else
		{
			return to;
		}
	}

	NavNode* to;
	NavNode* from;
	float weight;
};