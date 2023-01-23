
#include "MenuTicTacToe.h"
#include "TicTacToe.h"
void MenuTicTacToe::Draw()
{
	char a;
	std::cout << "Play";
	std::cin>>a;
	system("cls");
	TicTacToe tic;
	tic.SetPlayer();
}
