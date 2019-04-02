#include "GamePCH.h"
#include <MiniEngine.h>

int main()
{
	std::unique_ptr<Engine::GameApp> GameApp = std::make_unique<Engine::GameApp>();
	if (GameApp)
	{
		GameApp->AppInit();
		try
		{
			GameApp->AppRun();
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