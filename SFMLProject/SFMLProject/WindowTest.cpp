#include "WindowTest.h"
#include "Input.h"
#include "Time.h"

#pragma region constructor/destructor
WindowTest::WindowTest()
{
	shape = new sf::RectangleShape(sf::Vector2f(50, 50));
	text = new sf::Text();
	font = new sf::Font();
	if (!font->loadFromFile("../Fonts/Story Element DEMO.ttf")) return;
	text->setFont(*font);
	text->setString("FP");
	text->setCharacterSize(24);
}
WindowTest::~WindowTest()
{
	delete shape;
	shape = nullptr;

	delete text;
	text = nullptr;

	delete font;
	font = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods

#pragma endregion methods
#pragma region override
void WindowTest::OnDraw()
{
	Draw(shape);
	Draw(text);
}
void WindowTest::OnUpdate()
{
	if (Input::IsKeyDown(sf::Keyboard::D))
		shape->setPosition(shape->getPosition() + sf::Vector2f(1, 0));

	if (Input::IsKeyDown(sf::Keyboard::Q))
		shape->setPosition(shape->getPosition() + sf::Vector2f(-1, 0));
}
#pragma endregion override
