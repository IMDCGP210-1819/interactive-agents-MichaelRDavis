#pragma once

#include <SDL.h>
#undef main
#include <cstdint>
#include <memory>
#include <imgui.h>

class World;

class GameApp
{
public:
	GameApp();
	~GameApp();

	void Init();
	void Shutdown();

	void Update(float deltaTime);

	void GetInput(ImGuiIO& io, float deltaTime);

	void Clear();
	void SwapBuffers();
	void Draw();

	void DrawUI();

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
	int32_t m_mouseWheel;
	int32_t m_mousePosX;
	int32_t m_mousePosY;
	bool m_isShutdown;
	bool m_uiEnabled;

	std::unique_ptr<World> m_pWorld;
};