#pragma once

#include <cstdint>
#include <array>
#include <vector>
#include <functional>
#include <cstdint>

struct Node
{
	int32_t x;
	int32_t y;
};

namespace std
{
	template<> 
	struct hash<Node>
	{
		result_type operator()(const argument_type& node) const noexcept
		{
			return hash<int32_t>()(node.x ^ (node.y << 4));
		}
	};
}

class Grid
{
public:
	Grid(int32_t gridWidth, int32_t gridHeight);
	~Grid() = default;

	std::vector<Node> GetNeighbours(Node node) const;

	inline int32_t GetGridWidth() const
	{
		return m_gridWidth;
	}

	inline int32_t GetGridHeight() const
	{
		return m_gridHeight;
	}

protected:
	static std::array<Node, 4> m_dirs;
	int32_t m_gridWidth;
	int32_t m_gridHeight;
};