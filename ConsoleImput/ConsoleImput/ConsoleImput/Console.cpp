#include "Console.h"

void Console::SetCursorPosition(const int _x, const int _y)
{
	cursorPosition.X = _x;
	cursorPosition.Y= _y;
	SetConsoleCursorPosition(console, cursorPosition);
}
