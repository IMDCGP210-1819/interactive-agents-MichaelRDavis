#include "GamePCH.h"
#include <MiniEngine.h>

#include "Core/AppCore/App.h"
#include "Game/Asteroid.h"
#include "Core/Module/Game.h"

int main()
{
	std::unique_ptr<App> GameApp = std::make_unique<App>();

	std::unique_ptr<Game> GameInst = std::make_unique<Game>();
	std::unique_ptr<SpriteComponent> Background = std::make_unique<SpriteComponent>(0, "Content/Background.png");

	if (GameApp)
	{
		GameApp->AppInit();
		try
		{
			while (true)
			{
				GameApp->ProcessEvents();

				GameApp->Clear();

				//Background->Draw(GameApp->GetWindow()->GetWindow());

				GameApp->DisplayWindow();
			}
		}
		catch (const std::exception& exception)
		{
			std::cout << "FATAL_ERROR: " << exception.what() << std::endl;
			GameApp->AppExit();
		}
		GameApp->AppExit();
	}
	return 0;
}