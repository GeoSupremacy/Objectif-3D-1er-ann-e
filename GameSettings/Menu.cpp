#include "Menu.h"
#include "MenuTicTacToe.h"
#include <iostream>

void Menu::DisplayMenu()
{
	std::cout << "             Menu Games \n";
	std::cout << "Choose Game: \n";
	std::cout << "1 : " << "TicTacToe" <<"\n";
	std::cin >> cursor;
	if (cursor == 1)
	{
		system("cls");
		MenuTicTacToe menuTic;
		menuTic.Draw();

	}
	else
	{
		DisplayMenu();
	}
}
void Menu::DisplaySetting(std::string _game)
{
	if (_game == "TicTacToe")
	{
		count = count + 1;
		id = count;
	}

}
void Menu::Choose(int _choose)
{
	
		
	
}
