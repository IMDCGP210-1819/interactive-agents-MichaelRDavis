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

private:
	/**  */
	SDL_Window* m_window;

	/**  */
	std::string m_appTitle;

	/**  */
	int32_t m_width;

	/**  */
	int32_t m_height;
};
