#include "FlappyBird.h"
#include <conio.h>
#include <iostream>


#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26

void FlappyBird::DrawBird()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			SetCursorPosition(j + 2, i +9);
			std::cout << bird[i][j];
		}
		
	}
}
void FlappyBird::SetCursorPosition(const int _x, const int _y)
{
	cursorPosition.X = _x;
	cursorPosition.Y = _y;
	SetConsoleCursorPosition(console, cursorPosition);
}
