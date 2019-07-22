#include <memory>
#include "Game/GameApp.h"

int main()
{
	std::unique_ptr<GameApp> app = std::make_unique<GameApp>();
	app->Init();

	uint32_t tickCount = 0;

	while(!app->GetIsShutdown())
	{
		float deltaTime = SDL_GetTicks() - tickCount / 1000.0f;
		tickCount = SDL_GetTicks();
		app->Update(deltaTime);
	}

	app->Shutdown();

	return 0;
}