#pragma once

class World;
struct NavNode;
struct NavPath;

#include <vmath.h>

class NavGraph
{
public:
	NavGraph(World* world);
	~NavGraph();

	NavNode* GetRandomNode();
	NavPath* FindPath(const Vector2f startPosition, const Vector2f endPosition);

	void BuildGraph();
	void DrawGraph();

private:
	World* m_cachedWorld;
};