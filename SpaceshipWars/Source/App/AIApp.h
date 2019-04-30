#pragma once

class World;

/**
 * Wrapper class for an AI application.
 * Handles application startup, shutdown and update.
 */
class AIApp
{
public:
	/** Default constructor. */
	AIApp();

	/** Default destructor. */
	~AIApp();

	/** Initialize the application. */
	void Startup();

	/** Shutdown the application. */
	void Shutdown();

	/** Update the application, called once per frame */
	void Update();

	/** Process application messages. */
	void HandleMessages();

	/** Initiate draw calls, swap and clear buffer.  */
	void Render();

	/** Clear the buffer. */
	void Clear();

	/** Swap back buffers. */
	void SwapBuffers();

	/** Returns true if the application is currently running. */
	inline bool GetIsRunning() const
	{
		return m_isRunning;
	}

private:
	/** Pointer the native OS window. */
	SDL_Window* m_window;

	/** Pointer to the renderer object. */
	SDL_Renderer* m_renderer;

	/** Pointer to the world object. */
	std::unique_ptr<World> m_world;

	/** Name of the application window. */
	std::string m_appTitle;

	/** Width of the application window. */
	int32_t m_width;

	/** Height of the application window. */
	int32_t m_height;

	/** True if the application is currently running. */
	bool m_isRunning;
};
