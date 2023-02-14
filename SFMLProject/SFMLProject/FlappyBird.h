#pragma once
#include "Window.h"


class FlappyBird :public Window
{
#pragma region f/p
private:
	sf::RectangleShape* exit = nullptr;
	sf::RectangleShape* play = nullptr;
	sf::Text* text = nullptr;
	sf::Font* font = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FlappyBird();
	~FlappyBird() override;
#pragma endregion constructor/destructor
#pragma region methods
public:

#pragma endregion methods
#pragma region override
protected:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
#pragma endregion override

};

