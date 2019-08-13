#pragma once

class World;
struct NavNode;

class NavGraph
{
public:
	NavGraph(World* world);
	~NavGraph();

	NavNode* GetRandomNode();

	void BuildGraph();
	void DrawGraph();

private:
	World* m_cachedWorld;
};