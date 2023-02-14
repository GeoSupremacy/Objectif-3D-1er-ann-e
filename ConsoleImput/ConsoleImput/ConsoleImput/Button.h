#pragma once
#include <string>

class Rect;
class Button
{
#pragma region f/p
private:
	std::string content = "";
	std::string type = "";
	Rect* rect = nullptr;
#pragma endregion f/p
#pragma region constructor
public:
	Button() = default;
	Button(const std::string& _content, const std::string& _type,Rect* _rect);
	Button(const Button& _copy);
#pragma endregion constructor
#pragma region methods
	void OnCLick();
	Rect* GetReck()const;
#pragma endregion methods

};

