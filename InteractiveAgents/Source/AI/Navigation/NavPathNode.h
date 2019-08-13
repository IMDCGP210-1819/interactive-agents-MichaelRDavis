#pragma once

struct NavNode;

struct NavPathNode
{
	NavPathNode(NavPathNode* inPrevNode, NavNode* inPathNode, NavNode* inGoalNode)
	{
		prevNode = inPrevNode;
		pathNode = inPathNode;
		goalNode = inGoalNode;
		isClosed = false;
	}

	NavPathNode* prevNode;
	NavNode* pathNode;
	NavNode* goalNode;
	bool isClosed;
	float goal;
	float heuristic;
	float fitness;
};