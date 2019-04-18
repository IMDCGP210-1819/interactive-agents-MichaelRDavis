#pragma once

/**
 * 
 */
class NavGrid
{
public:
	/** Default constructor. */
	NavGrid();

	/** Default destructor. */
	~NavGrid();

	/** Draw the grid. */
	void DrawGrid();

	/** Grid width. */
	float m_GridWidth;

	/** Grid height. */
	float m_GridHeight;

	/** Number of grid cells in the X axis. */
	int m_GridsX;

	/** Number of grid cells in the Y axis. */
	int m_GridsY;
};