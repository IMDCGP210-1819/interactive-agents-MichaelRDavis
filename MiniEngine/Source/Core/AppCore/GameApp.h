#pragma once

namespace Engine
{
	class GameInstance;

	/**
	 * 
	 */
	class GameApp
	{
	public:
		/** Default constructor. */
		GameApp();

		/** Default destructor. */
		~GameApp();

		/** Initializes the application. */
		void AppInit();

		/** Runs the application. */
		void AppRun();

		/** Shuts down the application. */
		void AppExit();

	private:
		/** Smart pointer to the game instance. */
		std::unique_ptr<GameInstance> m_Instance;

		/** Handle to the application window. */
		sf::RenderWindow m_Window;

		/** Handle to the system time. */
		sf::Clock m_Clock;
	};
}