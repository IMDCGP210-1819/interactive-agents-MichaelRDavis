#pragma once

#include "AI/Navigation/NavNode.h"

struct NavPathNode
{
	NavPathNode(NavPathNode* inPrevNode, NavNode* inPathNode, NavNode* inGoalNode)
	{
		prevNode = inPrevNode;
		pathNode = inPathNode;
		goalNode = inGoalNode;
		isClosed = false;
		goal = 0.0f;
		heuristic = 0.0f;
		fitness = 0.0f;

		CalculateHeuristic();
	}

	void CalculateHeuristic()
	{
		if (prevNode)
		{
			goal = prevNode->goal + pathNode->CalculateCost(prevNode->pathNode);
		}
		else
		{
			goal = 0;
		}

		Vector2f diff = pathNode->position - goalNode->position;
		heuristic = diff.length();

		fitness = goal + heuristic;
	}

	NavPathNode* prevNode;
	NavNode* pathNode;
	NavNode* goalNode;
	bool isClosed;
	float goal;
	float heuristic;
	float fitness;
};