#pragma once

#include <SDL.h>
#include <vmath.h>

class Drawing
{
public:
	static void DrawPoint(SDL_Renderer* renderer, int32_t xPos, int32_t yPos, Vector4f color)
	{
		SDL_SetRenderDrawColor(renderer, color.x, color.y, color.z, color.w);
		SDL_RenderDrawPoint(renderer, xPos, yPos);
	}
};