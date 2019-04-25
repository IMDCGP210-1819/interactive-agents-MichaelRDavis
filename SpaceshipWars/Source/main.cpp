#include "GamePCH.h"
#include <MiniEngine.h>

int main()
{
	std::unique_ptr<Game> GameInst = std::make_unique<Game>();
	std::unique_ptr<SpriteComponent> Background = std::make_unique<SpriteComponent>(0, "Content/Background.png");

	if (GameInst)
	{
		try
		{
			while (true)
			{
				GameInst->Update();
			}
		}
		catch (const std::exception& exception)
		{
			std::cout << exception.what() << std::endl;
		}
	}
	return 0;
}