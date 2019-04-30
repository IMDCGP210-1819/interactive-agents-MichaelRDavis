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
	void DrawGrid(SDL_Renderer* renderer);

	/** Number of grid cells in the X axis. */
	int m_GridsX;

	/** Number of grid cells in the Y axis. */
	int m_GridsY;
};