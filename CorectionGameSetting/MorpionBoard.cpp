#include "MorpionBoard.h"
#include "MorpionGame.h"
#include "Utils.h"
#include <iostream>
MorpionBoard::MorpionBoard()
{
	Initialize();
}

MorpionBoard::~MorpionBoard()
{
	board.clear();
}

void MorpionBoard::Initialize()
{
	for (int i = 0; i < 9; i++)
	{
		board.push_back(0);
	}
}

int MorpionBoard::Win(std::vector<int> _board)
{
	for (int i = 0; i < 8; i++)
	{
		if (_board[wins[i][0]] != 0 && _board[wins[i][0]] == _board[wins[i][1]]
			&& _board[wins[i][1]] != 0 && _board[wins[i][2]])
		{

		}
	}
	return 0;
}

int MorpionBoard::Win() const
{
	return Win(board);
}

void MorpionBoard::ShowBoard() const
{
	int _k = 0;
	Utils::Log("----++---+++----");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << "| ";
			if (board[_k] == 0)
				std::cout << " |";
			else
			{
				if (board[_k] == -1)
					std::cout << "X |";
				else
					std::cout << "O |";
			}
		}
	}

	Utils::Log("\n----++---+++----");
}

void MorpionBoard::Reset()
{
	board.clear();
	Initialize();
}

int& MorpionBoard::At(const int _index)
{
	if (_index<0 || _index>board.size())
		throw std::exception("[Morpion board]=> index out of range");
	return board[_index];
}
