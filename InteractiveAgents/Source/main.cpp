#include <memory>
#include <iostream>
#include "Engine/AppFramework/GameApp.h"

int main()
{
	try
	{
		std::unique_ptr<GameApp> app = std::make_unique<GameApp>();
		app->Init();

		while (!app->GetIsShutdown())
		{
			float deltaTime = SDL_GetTicks();
			app->Update(deltaTime);
		}

		app->Shutdown();

	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	return 0;
}