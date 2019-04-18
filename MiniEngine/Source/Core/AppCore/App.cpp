#include "MiniPCH.h"
#include "App.h"

App::App()
{
	
}

App::~App()
{

}

void App::AppInit()
{
	m_Window = std::make_shared<Window>();
}

void App::AppExit()
{
	m_Window->DestroyWindow();
}

void App::ProcessEvents()
{
	sf::Event Event;
	while (m_Window->GetWindow()->pollEvent(Event))
	{
		switch (Event.type)
		{
		case sf::Event::Closed:
			AppExit();
		default:
			break;
		}
	}
}

void App::DisplayWindow()
{
	m_Window->GetWindow()->display();
}

void App::Clear()
{
	m_Window->GetWindow()->clear(sf::Color::Black);
}
