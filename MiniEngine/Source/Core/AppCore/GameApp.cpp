#include "MiniPCH.h"
#include "GameApp.h"
#include "Gameplay/GameFramework/GameInstance.h"

Engine::GameApp::GameApp()
{
	m_Instance = std::make_unique<GameInstance>();
}

Engine::GameApp::~GameApp()
{

}

void Engine::GameApp::AppInit()
{
	m_Window.create(sf::VideoMode(800, 600), "Spaceship Wars");
}

void Engine::GameApp::AppRun()
{
	while (m_Window.isOpen())
	{
		sf::Event Event;
		while (m_Window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				m_Window.close();
			}

			sf::Time DeltaTime = m_Clock.restart();
		}

		m_Window.clear();
		m_Window.display();
	}
}

void Engine::GameApp::AppExit()
{
	m_Window.close();
}
