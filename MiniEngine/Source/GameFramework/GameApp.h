#pragma once

namespace Engine
{
	class GameApp
	{
	public:
		GameApp();
		~GameApp();

		void AppInit();
		void AppRun();
		void AppExit();

	private:
		sf::RenderWindow m_Window;
	};
}