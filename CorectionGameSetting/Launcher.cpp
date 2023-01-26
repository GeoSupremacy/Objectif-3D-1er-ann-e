#include "Launcher.h"
#include "LauncherItem.h"
#include "Object.h"
#include "Utils.h"
#include "IGame.h"
#include <iostream>

Launcher::Launcher(const std::initializer_list<LauncherItem*> _items)
{
	for (LauncherItem* _item : _items)
		items.push_back(_item);
}

Launcher::~Launcher()
{
	delete currentGame;
}

void Launcher::Update()
{
	while (isOpen)
	{
		try
		{
			Utils::ClearConsole();

			const size_t _size = items.size();
			for (size_t i = 0; i < _size; i++)
			{
				std::cout << std::to_string(i + 1) + ": ";
			}

			//Display();
			currentGame == Utils::UserChoise<int>("Choose: ",0,0,0) - 1;
			if (gameIndex == items.size())
			{
				isOpen = false;
				continue;
			}
			if (gameIndex <0 || gameIndex > items.size())
			{
				//throw std::e
					//StatGame();

			}
		}
		catch (const std::exception& _e)
		{
			Utils::LogError(_e.what());
			Utils::Pause();
			Utils::ClearConsole();
			Utils::LoadingBar("Error in " + currentGame->GameName() + ", closing game !");
		}
	}
	Utils::ClearConsole();
	Utils::LoadingBar("Quitte Laucher")
}

void Launcher::Open()
{
	Update();
}
