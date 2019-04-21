#include "MiniPCH.h"
#include "AStar.h"
#include "GameSystems/AI/Navigation/NavNode.h"
#include "GameSystems/AI/Navigation/NavPath.h"

AStar::AStar()
{

}

AStar::~AStar()
{

}

float AStar::CalculateHeuristic(const NavNode* StartNode, const NavNode* EndNode)
{
	return 0.0f;
}

bool AStar::Search(const NavGraph& Graph, const NavNode* StartNode, const NavNode* EndNode)
{
	std::unordered_map<const NavNode*, AStarData> AStarMap;

	std::vector<const NavNode*> OpenSet;

	const NavNode* CurrentNode = StartNode;
	AStarMap[CurrentNode].IsClosedSet = true;

	do
	{
		for (auto Path : CurrentNode->GetPathList())
		{
			const NavNode* NextNode = Path->GetToNode();
		}

	} while (CurrentNode != EndNode);

	return CurrentNode == EndNode ? true : false;
}
