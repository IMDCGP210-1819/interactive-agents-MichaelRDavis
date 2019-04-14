#include "GamePCH.h"
#include <MiniEngine.h>

int main()
{
	std::unique_ptr<App> GameApp = std::make_unique<App>();
	if (GameApp)
	{
		GameApp->AppInit();
		try
		{
			while (GameApp->IsWindowOpen())
			{
				GameApp->Clear();
				GameApp->ProcessEvents();
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