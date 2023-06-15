#include "Button.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include "../../Manager/FontManager.h"

#pragma region constructor
Engine::UI::Button::Button(const std::string& _text, float _width, float _height) : super()
{
	width = _width;
	height = _height;
	shape = new sf::RectangleShape(sf::Vector2f(width, height));
	shape->setOrigin(width/2, height/2);
	shape->setFillColor(baseColor);
	text.setString(_text);
	text.setFont(*Manager::FontManager::Instance()->GetFont("Arial"));
	text.setCharacterSize(24);
	text.setOrigin(shape->getOrigin());
	text.setFillColor(sf::Color::White);
}
Engine::UI::Button::Button(const std::string& _text, float _width, float _height, Action<> _onClick) 
	: self(_text, _width, _height)
{
	onClick = _onClick;

}
Engine::UI::Button::Button(const Button& _copy) : super(_copy)
{
	width = _copy.width;
	height = _copy.height;
	text = _copy.text;
	baseColor = _copy.baseColor;
	enterColor = _copy.enterColor;
	onClick = _copy.onClick;

}
#pragma endregion constructor
#pragma region method
void Engine::UI::Button::SetBackgroundColor(const sf::Color& _color)
{
	checkLow((shape != nullptr), "shape is nullptr!")
	baseColor = _color;
	shape->setFillColor(baseColor);
}
void Engine::UI::Button::SetPosition(const PrimaryType::Vector2& _position)
{
	super::SetPosition(_position);
	const sf::FloatRect _shpapeBounds = shape->getGlobalBounds();
	const sf::FloatRect _textBounds = text.getGlobalBounds();
	const float _x = _shpapeBounds.left + (_shpapeBounds.width / 2) - (_textBounds.width / 2);
	const float _y = _shpapeBounds.top + (_shpapeBounds.height / 2) - _textBounds.height;
	text.setPosition(_x, _y);
}
#pragma endregion method
#pragma region override
void Engine::UI::Button::Draw(sf::RenderWindow* _window)
{
	super::Draw(_window);
	_window->draw(text);
}
void Engine::UI::Button::OnPointerClick(const sf::Event& _event)
{
	checkLow((shape != nullptr), "shape is nullptr!")
	if (!canInteract) return;
	onClick.Invoke();
}
void Engine::UI::Button::OnPointerEnter() 
{
	checkLow((shape != nullptr), "shape is nullptr!")
	if (!canInteract) return;
	shape->setFillColor(enterColor);
}
void Engine::UI::Button::OnPointerExit() 
{
	checkLow((shape != nullptr), "shape is nullptr!")
	if (!canInteract) return;
	shape->setFillColor(baseColor);
}
#pragma endregion override