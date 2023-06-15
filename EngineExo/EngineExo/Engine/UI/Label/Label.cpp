#include "Label.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../Manager/FontManager.h"
#include "../../Manager/EventSystem/EventSystem.h"


#pragma region constructor
Engine::UI::Label::Label() :super()
{
	text.setFont(*Manager::FontManager::Instance()->GetFont("Arial"));
	text.setCharacterSize(12);
	text.setString("");
	Manager::EventSystem::Instance()->Register(this);
}
Engine::UI::Label::Label(const char* _text, int _characterSize, const char* _fontName) :super()
{
	text.setString(_text);
	text.setCharacterSize(_characterSize);
	text.setFont(*Manager::FontManager::Instance()->GetFont(_fontName));
}
Engine::UI::Label::Label(const Label& _copy) 
{
	text = _copy.text;
	Manager::EventSystem::Instance()->Register(this);
}
#pragma endregion constructor
#pragma region method
void Engine::UI::Label::SetFont(const char* _fontName)
{
	text.setFont(*Manager::FontManager::Instance()->GetFont(_fontName));
}
void Engine::UI::Label::SetCharacterSize(int _value)
{
	text.setCharacterSize(_value);
}
void Engine::UI::Label::SetColor(const sf::Color& _color)
{
	text.setFillColor(_color);
}
void Engine::UI::Label::SetPosition(const PrimaryType::Vector2& _position)
{
	text.setPosition(_position);
}
void Engine::UI::Label::SetRotation(float _angle)
{
	text.setRotation(_angle);
}
void Engine::UI::Label::SetScale(const PrimaryType::Vector2& _scale)
{
	text.setScale(_scale);
}
void Engine::UI::Label::SetOrigin(const PrimaryType::Vector2& _origin)
{
	text.setOrigin(_origin);
}
void Engine::UI::Label::SetLabel(const char* _label)
{
	text.setString(_label);
}
sf::Shape* Engine::UI::Label::Shape() const
{
	return nullptr;
}
Engine::PrimaryType::Vector2 Engine::UI::Label::Position() const
{
	return text.getPosition();
}
float Engine::UI::Label::Rotation() const
{
	return text.getRotation();
}
Engine::PrimaryType::Vector2 Engine::UI::Label::Scale() const
{
	return text.getScale();
}
Engine::PrimaryType::Vector2 Engine::UI::Label::Origin() const
{
	return text.getOrigin();
}
Engine::PrimaryType::String Engine::UI::Label::LabelText() const
{
	return text.getString().toAnsiString().c_str();
}
void Engine::UI::Label::Draw(sf::RenderWindow* _window)
{
	_window->draw(text);
}
#pragma endregion method