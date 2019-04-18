#include "MiniPCH.h"
#include "Window.h"

Window::Window()
{
	InitializeWindow();
}

Window::~Window()
{
	DestroyWindow();
}

void Window::InitializeWindow()
{ 
	m_Width = sf::VideoMode::getDesktopMode().width;
	m_Height = sf::VideoMode::getDesktopMode().height;

	unsigned int WindowStyle = sf::Style::Default;

	m_Window = new sf::RenderWindow(sf::VideoMode(m_Width, m_Height), "Spaceship Wars", WindowStyle);
}

void Window::DestroyWindow()
{
	delete m_Window;
}

