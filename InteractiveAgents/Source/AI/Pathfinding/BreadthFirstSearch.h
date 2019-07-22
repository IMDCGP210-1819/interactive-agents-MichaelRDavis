#pragma once

#include <unordered_map>
#include "AI/Navigation/Grid.h"

class BreadthFirstSearch
{
public:
	BreadthFirstSearch(Grid* graph);
	~BreadthFirstSearch() = default;

	std::unordered_map<Node, Node> Search(Node start);

private:
	Grid* m_graph;
};