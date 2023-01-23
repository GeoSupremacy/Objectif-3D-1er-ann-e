#pragma once
#include <iostream>
#include <string>
class TicTacToe 
{
private:
	
	int digit, 
		firstPlayer = 0, 
		secondPlayer = 0;
	const int SIZE = 3;
	char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	char copySpace[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	int row, column;
	char token ='X';
	char replay;
	std::string playerOne;
	std::string playerTwo;
	bool isFilled = false;
	bool isStill = true;
public:
	TicTacToe() = default;

public:
	void Board();
	void Position();
	void SetSymbole(char _symbole);
	void SetLocation(int _position);
	void SetValidLocation();
	void WhoIsWinner();
	bool CheckWin();
	bool CheckRow();
	bool CheckCols();
	bool CheckDiags();
	bool CheckFilled();
	void Still();
	void CheckReplay();
	void SetPlayer();
	void SetColor(int _color);
	void SetValue(int _colum, int _row);
	void Count();
};

