#include "GamePCH.h"
#include <MiniEngine.h>

#include "Game/Background.h"

int main()
{
	std::unique_ptr<Game> GameInst = std::make_unique<Game>();

	std::unique_ptr<Background> GameBackgroud = std::make_unique<Background>();

	if (GameInst)
	{
		GameInst->Initialize();
		float DeltaTime = SDL_GetTicks();
		try
		{
			while (true)
			{
				GameInst->Update(DeltaTime);
				GameInst->Draw();
			}
		}
		catch (const std::exception& exception)
		{
			std::cout << exception.what() << std::endl;
		}
	}
	return 0;
}