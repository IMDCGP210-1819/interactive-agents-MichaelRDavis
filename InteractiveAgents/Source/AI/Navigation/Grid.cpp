#include "Grid.h"

std::array<Node, 4> Grid::m_dirs = { Node{1, 0}, Node{0, -1}, Node{-1, 0,}, Node{0, 1} };

Grid::Grid(int32_t gridWidth, int32_t gridHeight)
	: m_gridWidth(gridWidth)
	, m_gridHeight(gridHeight)
{

}

std::vector<Node> Grid::GetNeighbours(Node node) const
{
	std::vector<Node> nodes;
	for (Node dir : m_dirs)
	{
		Node next{ node.x + dir.x, node.y + dir.y };
		nodes.push_back(next);

		if (node.x + node.y % 2 == 0)
		{
			std::reverse(nodes.begin(), nodes.end());
		}
	}

	return nodes;
}

