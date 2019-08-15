#pragma once

#include <SDL.h>
#include <vmath.h>

/**
 * Debug drawing
 */
class Drawing
{
public:
	/** Draws a point */
	static void DrawPoint(SDL_Renderer* renderer, int32_t xPos, int32_t yPos, Vector4f color)
	{
		SDL_SetRenderDrawColor(renderer, color.x, color.y, color.z, color.w);
		SDL_RenderDrawPoint(renderer, xPos, yPos);
	}

	/** Draws a line */
	static void DrawLine(SDL_Renderer* renderer, Vector2i startLocation, Vector2i endLocation, Vector4f color)
	{
		SDL_SetRenderDrawColor(renderer, color.x, color.y, color.z, color.w);
		SDL_RenderDrawLine(renderer, startLocation.x, startLocation.y, endLocation.x, endLocation.y);
	}
};