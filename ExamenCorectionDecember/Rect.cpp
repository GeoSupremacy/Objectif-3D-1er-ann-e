#include"Rect.h"


#pragma region constructor/destructor

#pragma endregion constructor/destructor
#pragma region methods

#pragma endregion methods

Rect::Rect(int _x, int _y, int _width, int _height)
{
	 x = _x;
	 y = _y;
	 width = _width;
	 height = _height;
}
Rect::Rect(const Rect& _copy)
{
	x = _copy.x;
	y = _copy.y;
	width = _copy.width;
	height = _copy.height;
}

int Rect::X()
{
	return x;
}

int Rect::Y()
{
	return y;
}

int Rect::Width()
{
	return width;
}

int Rect::Height()
{
	return height;
}
