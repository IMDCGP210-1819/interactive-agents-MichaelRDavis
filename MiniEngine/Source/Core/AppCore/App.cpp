#include "MiniPCH.h"
#include "App.h"

App::App()
{
	AppInit();
}

App::~App()
{
	AppExit();
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
	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
		case SDL_QUIT:
			AppExit();
			break;
		}
	}
}
