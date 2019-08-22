#include <memory>
#include "Engine/AppFramework/GameApp.h"

int main()
{
	std::unique_ptr<GameApp> app = std::make_unique<GameApp>();
	app->Init();

	while(!app->GetIsShutdown())
	{
		float deltaTime = SDL_GetTicks();
		app->Update(deltaTime);
	}

	app->Shutdown();

	return 0;
}