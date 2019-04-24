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

}

void App::DisplayWindow()
{
	
}

void App::Clear()
{
	
}
