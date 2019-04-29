#pragma once

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
	void HandleMessages();;

	/**  */
	inline bool GetIsRunning() const
	{
		return m_isRunning;
	}

private:
	/**  */
	SDL_Window* m_window;

	/**  */
	std::string m_appTitle;

	/**  */
	int32_t m_width;

	/**  */
	int32_t m_height;

	/**  */
	bool m_isRunning;
};
