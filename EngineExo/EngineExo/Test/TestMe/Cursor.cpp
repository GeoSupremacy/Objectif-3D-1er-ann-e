#include "Cursor.h"
#include <SFML/Graphics/RectangleShape.hpp>


Test::Cursor::Cursor() 
{
	shape =  new sf::RectangleShape(sf::Vector2f(width, height));
	shape->setPosition(300, 300);
	shape->setFillColor(sf::Color::White);
	globalPositionR = shape->getPosition().x;
	circle.setFillColor(sf::Color::White);
	circle.setOrigin(75.f / 2, 75.f / 2);
	circle.setPosition(300, 300);
}

void Test::Cursor::OnPointerClick(const sf::Event& _event)
{
	
}
void Test::Cursor::Update()
{
	if (circlePosition >= 700)
		circle.setPosition(globalPositionR, 250);
	else if (circlePosition <= globalPositionR)
		circle.setPosition(700, 250);
}
