#include "BreadthFirstSearch.h"
#include <queue>

BreadthFirstSearch::BreadthFirstSearch(Grid* graph)
	: m_graph(graph)
{

}

std::unordered_map<Node, Node> BreadthFirstSearch::Search(Node start)
{
	std::queue<Node> locations;
	locations.push(start);

	std::unordered_map<Node, Node> visited;
	visited[start] = start;

	while (!locations.empty())
	{
		Node currentNode = locations.front();
		locations.pop();

		for (Node nextNode : m_graph->GetNeighbours(currentNode))
		{
			if (visited.find(nextNode) == visited.end())
			{
				locations.push(nextNode);
				visited[nextNode] = currentNode;
			}
		}
	}

	return visited;
}