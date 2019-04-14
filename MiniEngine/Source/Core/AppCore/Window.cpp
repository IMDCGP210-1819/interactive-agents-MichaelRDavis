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
	m_Window = new sf::RenderWindow(sf::VideoMode(640, 480), "Spaceship Wars", sf::Style::Close);
}

void Window::DestroyWindow()
{
	delete m_Window;
}

