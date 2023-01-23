#include "LauncherItem.h"
#include "Utils.h"
#include "IGame.h"

/*
LauncherItem::LauncherItem(IGame* _game)
{
	game = _game;
}

LauncherItem::LauncherItem(const LauncherItem& _copy)
{
	game = _copy.game;
}

LauncherItem::~LauncherItem()
{
	delete game;
}

void LauncherItem::OnClick()
{
	if (game == nullptr) throw std::exception("[Laugheer Item] => current game is null!");
	Utils::ClearConsole();
	Utils::LoadingBar("Choose");
	game->OnStart();
	game->OnDisplayMenu();
	game->OnUpdate();
	game->OnEnd();
}
void LauncherItem::Display()
{
	Utils::Log(game->GameName());
}

IGame* LauncherItem::Game()
{
	return game;
}
*/

