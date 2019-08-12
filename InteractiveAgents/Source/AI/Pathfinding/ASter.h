#pragma once

class NavNode;

class AStar
{
public:
	AStar();
	~AStar();

	void Search(NavNode* startNode, NavNode* goalNode);

private:
	NavNode* m_goalNode;
	NavNode* m_startNode;
};

