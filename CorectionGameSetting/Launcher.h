#pragma once
#include"Object.h"
#include<vector>

class IGame;
class LauncherItem;

class Launcher : public Object
{
private:
	bool isOpen = false;
	int gameIndex = -1;
	IGame* currentGame = nullptr;
	std::vector< LauncherItem*> items = std::vector<LauncherItem* > ();
public:
	Launcher() = default;
	Launcher(const std::initializer_list<LauncherItem*> _items);
	~Launcher() override;

private:
	void Update();
public:
	void Open();
};

