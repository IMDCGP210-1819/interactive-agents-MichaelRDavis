#include "GamePCH.h"
#include <MiniEngine.h>

int main()
{
	std::unique_ptr<App> GameApp = std::make_unique<App>();

	std::unique_ptr<SpriteComponent> Background = std::make_unique<SpriteComponent>(0, "Content/Background.png");

	if (GameApp)
	{
		GameApp->AppInit();
		try
		{
			while (GameApp->IsWindowOpen())
			{
				GameApp->ProcessEvents();

				GameApp->Clear();

				Background->Draw(GameApp->GetWindow()->GetWindow());

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