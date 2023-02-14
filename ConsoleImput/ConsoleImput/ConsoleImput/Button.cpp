#include "Button.h"
#include "Rect.h"
#include "Console.h"
#include <iostream>

#pragma region constructor
Button::Button(const std::string& _content, const std::string& _type, Rect* _rect)
{
	content = _content;
	rect = _rect;
	type = _type;
	Console::SetCursorPosition(_rect->X(), _rect->Y());
	std::cout << _content;
}

Button::Button(const Button& _copy)
{
	content = _copy.content;
	rect = _copy.rect;
	type = _copy.type;
}
#pragma endregion constructor
#pragma region methods
void Button::OnCLick()
{
	if(type =="list")
		std::cout << content << "On click!" << std::endl;
	else if (type == "recherche")
	{
		std::cin >> content;
		std::cout << content << std::endl;
	}
	else
	{
		content = "The type doesn't exist";
	}
}
Rect* Button::GetReck() const
{
	return rect;
}
#pragma endregion methods

