#pragma once

#include <SDL.h>
#undef main
#include <cstdint>
#include <memory>

class World;

class GameApp
{
public:
	GameApp();
	~GameApp();

	void Init();
	void Shutdown();

	void Update(float deltaTime);

	void Clear();
	void SwapBuffers();
	void Draw();

	inline SDL_Window* GetWindow() const
	{
		return m_pWindow;
	}

	inline SDL_Renderer* GetRenderer() const
	{
		return m_pRenderer;
	}

	inline bool GetIsShutdown() const
	{
		return m_isShutdown;
	}

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int32_t m_windowWidth;
	int32_t m_windowHeight;
	bool m_isShutdown;

	std::unique_ptr<World> m_pWorld;
};