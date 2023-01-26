#pragma once
#include"Object.h"

struct Rect : Object
{
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Rect() = default;
	Rect(int _x, int _y, int _width, int _height);
	Rect(const Rect &_copy);
#pragma endregion constructor/destructor
#pragma region methods
public:
	int X();
	int Y();
	int Width();
	int Height();
#pragma endregion methods
#pragma region override
public:

#pragma endregion override
#pragma region operator
public:

#pragma endregion operator
};