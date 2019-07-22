#pragma once

#include "AI/Navigation/Grid.h"

class DijkstraSearch
{
public:
	DijkstraSearch(Grid* graph);
	~DijkstraSearch() = default;

	void Search(Node start, Node goal);

private:
	Grid* m_graph;
};