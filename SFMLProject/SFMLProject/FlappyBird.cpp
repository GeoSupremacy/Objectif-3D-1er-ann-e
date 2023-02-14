#include "FlappyBird.h"
#include "Input.h"
#include "Time.h"

#pragma region constructor/destructor
FlappyBird::FlappyBird()
{
	exit = new sf::RectangleShape(sf::Vector2f(200, 200));
	exit->setPosition(450, 500);
	play = new sf::RectangleShape(sf::Vector2f(200, 200));
	exit->setPosition(100, 500);

	text = new sf::Text();
	font = new sf::Font();

	if (!font->loadFromFile("../Fonts/Story Element DEMO.ttf")) return;
	text->setFont(*font);
	text->setString("Button");
	text->setCharacterSize(24);
}
FlappyBird::~FlappyBird()
{
	delete exit;
	exit = nullptr;

	delete play;
	play = nullptr;

	delete text;
	text = nullptr;

	delete font;
	font = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods
void FlappyBird::OnDraw()
{
	Draw(exit);
	Draw(play);
}
#pragma endregion methods




