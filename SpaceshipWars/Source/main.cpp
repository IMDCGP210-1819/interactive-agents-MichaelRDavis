#include "stdafx.h"
#include "App/AIApp.h"

int main()
{
	std::unique_ptr<AIApp> app = std::make_unique<AIApp>();
	try
	{
		app->Startup();
		while (app->GetIsRunning())
		{
			app->Update();
			app->Render();
		}
		app->Shutdown();
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
		app->Shutdown();
	}

	return 0;
}