#pragma once

class World;

/**
 * 
 */
class AIApp
{
public:
	/**  */
	AIApp();

	/**  */
	~AIApp();

	/**  */
	void Startup();

	/**  */
	void Shutdown();

	/**  */
	void Update();

	/**  */
	void HandleMessages();

	/**  */
	void Render();

	/**  */
	void Clear();

	/**  */
	void SwapBuffers();

	/**  */
	inline bool GetIsRunning() const
	{
		return m_isRunning;
	}

private:
	/**  */
	SDL_Window* m_window;

	/**  */
	SDL_Renderer* m_renderer;

	/**  */
	std::unique_ptr<World> m_world;

	/**  */
	std::string m_appTitle;

	/**  */
	int32_t m_width;

	/**  */
	int32_t m_height;

	/**  */
	bool m_isRunning;
};
