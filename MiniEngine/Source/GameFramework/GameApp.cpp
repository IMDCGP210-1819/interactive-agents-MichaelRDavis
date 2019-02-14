#include "MiniPCH.h"
#include "GameFramework/GameApp.h"

Engine::GameApp::GameApp()
{

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
		}

		m_Window.clear();
		m_Window.display();
	}
}

void Engine::GameApp::AppExit()
{

}
