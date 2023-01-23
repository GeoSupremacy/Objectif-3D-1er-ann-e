#include "TicTacToe.h"
#include "Menu.h"
#include <Windows.h>

void TicTacToe::Board()
{
	
	SetColor(3);
		std::cout << "   |   |    \n";
		std::cout << " "; SetValue(0, 0); std::cout << " | "; SetValue(0, 1); std::cout << " | "; SetValue(0, 2); std::cout << "   \n";
		std::cout << "___|___|___ \n";
		std::cout << "   |   |    \n";
		std::cout << " "; SetValue(1, 0); std::cout << " | "; SetValue(1, 1); std::cout << " | "; SetValue(1, 2); std::cout << "   \n";
		std::cout << "___|___|___ \n";
		std::cout << "   |   |    \n";
		std::cout << " "; SetValue(2, 0); std::cout<< " | "; SetValue(2, 1); std::cout << " | "; SetValue(2, 2); std::cout << "   \n";
		std::cout << "   |   |    \n";
}
void TicTacToe::Position()
{
	
	SetSymbole(token);
	SetLocation(digit);
	SetValidLocation();
	
}
void TicTacToe::SetSymbole(char _symbole)
{
	 
	if (token == 'X')
	{
		SetColor(1);
		
		std::cout << playerOne << " please enter: ";
		std::cin >> digit;
		if (digit <= 0 || digit >= 10)
			return;
		system("cls");
	}
	if (token == 'O')
	{
		SetColor(2);
		
		std::cout << playerTwo << " please enter: ";
		std::cin >> digit;
		if (digit <= 0 || digit >= 10)
			return;
		system("cls");
	}
}
void TicTacToe::SetLocation(int _position)
{
	switch (_position)
	{
	case 1:
		row = 0;
		column = 0;
		break;
	case 2:
		row = 1;
		column = 0;
		break;
	case 3:
		row = 2;
		column = 0;
		break;
	case 4:
		row = 0;
		column = 1;
		break;
	case 5:
		row = 1;
		column = 1;
		break;
	case 6:
		row = 2;
		column = 1;
		break;
	case 7:
		row = 0;
		column = 2;
		break;
	case 8:
		row = 1;
		column = 2;
		break;
	case 9:
		row = 2;
		column = 2;
		break;
	default:
		std::cout << "Invalid !!!\n";
		system("cls");
		break;
	}
}
bool TicTacToe::CheckWin()
{
	 CheckRow();
	 CheckCols();
	 CheckDiags();
	 CheckFilled();
	 return isStill;
}
bool TicTacToe::CheckRow()
{
	for(int i=0; i<3;i++)
	{
		if (space[i][0] == space[i][1] && space[i][1] == space[i][2])
		{
			isStill = false;
			return isStill;
		}
	}
	return isStill;
}
bool TicTacToe::CheckCols()
{
	for (int i = 0; i <3; i++)
	{
		if (space[0][i] == space[1][i] && space[1][i] == space[2][i])
		{
	
			isStill = false;
			return isStill;
		}
	}
	return isStill;
}
bool TicTacToe::CheckDiags()
{
	
		if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
		{
			isStill = false;
			return isStill;
		}
		return isStill;
}
bool TicTacToe::CheckFilled()
{
	int count = 0;
	for (int y = 0; y < 3; y++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (space[y][i] == 'X' || space[y][i] == 'O')
			{
				count = count + 1;
			}
			
		}
	}
	if (count == 9)
	{
		isStill = false;
		isFilled = true;
	}
	return isStill;
}
void TicTacToe::Still()
{
	while(isStill)
	{
		Count();
		Board();
		Position();
		CheckWin();
	}
	WhoIsWinner();
	
}
void TicTacToe::SetValidLocation()
{
	if(token =='X' && space[column][row] !='X' && space[column][row] !='O')
	{
		SetColor(1);
		space[column][row] = 'X';
		token = 'O';
	}
	else if(token == 'O' && space[column][row] != 'X' && space[column][row] != 'O')
	{
		SetColor(2);
		space[column][row] = 'O';
		token = 'X';
	}
	else 
	{
		std::cout << " There  is no empty" << std::endl;
	}
	
}
void TicTacToe::WhoIsWinner()
{
	if (token == 'X' && isFilled == false)
	{
		SetColor(2);
		std::cout << playerTwo << " Wins!" << std::endl;
		secondPlayer = secondPlayer + 1;

	}
	else if (token == 'O' && isFilled == false)
	{
		SetColor(1);
		std::cout << playerOne << " Wins!" << std::endl;
		firstPlayer = firstPlayer + 1;
	}
	else
	{
		SetColor(3);
		std::cout << "Nice draw!" << std::endl;
	}
	std::cout << "Want you replay? (y/n) ?" << std::endl;
	std::cin >> replay;
	CheckReplay();
}
void TicTacToe::CheckReplay()
{
	if(replay =='y')
	{
		system("cls");
		isStill = true;
		isFilled = false;
		for (int y = 0; y < 3; y++)
		{
			for (int i = 0; i < 3; i++)
			{
				space[y][i] = copySpace[y][i];
			}
		}
		 
		Still();
	}
	else
	{
		system("cls");
		Menu menu;
		menu.DisplayMenu();
	}
}
void TicTacToe::SetPlayer()
{
	SetColor(3);

	std::string  _playerOne;
	std::string  _playerTwo;
	std::cout << " Player One: ";
	std::cin >> _playerOne;
	std::cout << std::endl;
	std::cout << " Player Two: ";
	std::cin >> _playerTwo;
	playerOne = _playerOne;
	playerTwo = _playerTwo;
	system("cls");
	Still();

}
void TicTacToe::SetColor(int _color)
{
	if (_color == 1)
	{
		const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(_hConsole, 1);
	}
		if (_color == 2)
		{
			const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(_hConsole, 6);
		}
			if (_color == 3)
			{
				const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(_hConsole, 7);
			}
}
void TicTacToe::Count()
{
	SetColor(1);
	std::cout << playerOne << ": "<< firstPlayer << "  "; 
	SetColor(2);
	std::cout<< playerTwo << ": " << secondPlayer << std::endl;
	
}
void TicTacToe::SetValue(int _colum, int _row)
{
	
	if (space[_colum][_row] == 'X')
	{
		SetColor(1);

		std::cout << space[_colum][_row];
	}
	else if (space[_colum][_row] == 'O')
	{
		SetColor(2);
		std::cout << space[_colum][_row];
	}
	else
	{
		SetColor(3);
		std::cout << space[_colum][_row];
	}
	SetColor(3);
	
}