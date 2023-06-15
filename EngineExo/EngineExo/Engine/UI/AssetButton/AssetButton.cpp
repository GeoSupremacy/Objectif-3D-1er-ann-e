#include "AssetButton.h"

#include "../../Manager/FontManager.h"
#include "../../PrimaryType/Vector2/Vector2.h"


#include <SFML/Graphics/RectangleShape.hpp>


Engine::UI::AssetButton::AssetButton(const std::string& _text, float _width, float _height, Object* _object, const Action<Object*>& _onCLick) : super()
{
	width = _width;
	height = _height;
	shape = new sf::RectangleShape(PrimaryType::Vector2(_width, _height));
	shape->setFillColor(baseColor);
	text.setFont("Arial");//font
	text.setString(_text);
	//Origine
	text.setFillColor(sf::Color::Black);
	OnCLick = _onCLick;
	object = _object;

}
Engine::UI::AssetButton::AssetButton(const AssetButton& _copy) : super(_copy)
{
	width = _copy.width;
	height = _copy.height;
	shape = _copy.shape;
	text = _copy.text;
	OnCLick = _copy.OnCLick;
	object = _copy.object;
}


void Engine::UI::AssetButton::SetBackGroundColor(const sf::Color& _color)
{
	checkLow((shape != nullptr), "shape is nullptr!")
	if (!canInteract) return;
	shape->setFillColor(_color);
}

void Engine::UI::AssetButton::OnPointerEnter()
{
	checkLow((shape != nullptr), "shape is nullptr!")
	if (!canInteract) return;
	shape->setFillColor(enterColor);
}

void Engine::UI::AssetButton::OnPointerExit()
{
	checkLow((shape != nullptr), "shape is nullptr!")
	if (!canInteract) return;
	shape->setFillColor(baseColor);
}
void Engine::UI::AssetButton::OnPointerClick(const sf::Event& _event)
{
	checkLow((shape != nullptr), "shape is nullptr!")
	if (!canInteract) return;
	OnCLick.Invoke(nullptr); //TODO replace nullptr with owner object.
}
void Engine::UI::AssetButton::SetPosition(const PrimaryType::Vector2& _position)
{
	super::SetPosition(_position);
	const sf::FloatRect _shapeBounds = shape->getGlobalBounds();
	const sf::FloatRect _textBounds = text.getGlobalBounds();
	const float _x = _shapeBounds.left + (_shapeBounds.width / 2) - (_textBounds.width / 2);
	const float _y = _shapeBounds.top + (_shapeBounds.height / 2) - (_textBounds.height / 2);
	text.setPosition(_x, _y);
}

void Engine::UI::AssetButton::Draw(sf::RenderWindow* _window)
{
	super::Draw(_window);
	_window->draw(text);
}
