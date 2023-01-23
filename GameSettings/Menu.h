#pragma once
#include "MenuTicTacToe.h"
#include <string>
class Menu : public MenuTicTacToe
{
private:
	int count = 0;
	int id = 0;
	std::string idT = "TicTacToe";
	int cursor = 0;
public:
	Menu() = default;
	void virtual DisplayMenu();
	void virtual DisplaySetting(std::string _game);
	void Choose(int _choose);
};

