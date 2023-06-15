#pragma once
#include "../Element/UIElement.h"

namespace Engine::UI
{
	class Label : public UIElement
	{
		DECLARE_CLASS_INFO(Label, UIElement)
#pragma region f/p
	private:
		sf::Text text = sf::Text();
#pragma endregion f/p
#pragma region constructor
	public:
		Label();
		Label(const char* _text, int _characterSize = 12, const char* _fontName = "Arial");
#pragma endregion constructor
#pragma region methods
	public:
		void SetFont(const char* _fontName);
		void SetCharacterSize(int _value);
		void SetColor(const sf::Color& _color);
#pragma endregion methods
#pragma region override
	public:
		virtual void SetPosition(const PrimaryType::Vector2& _position);
		virtual void SetRotation(float _angle);
		virtual void SetScale(const PrimaryType::Vector2& _scale);
		virtual void SetOrigin(const PrimaryType::Vector2& _origin);
		virtual void SetLabel(const char* _label);
		virtual sf::Shape* Shape() const;
		virtual PrimaryType::Vector2 Position() const;
		virtual float Rotation() const;
		virtual PrimaryType::Vector2 Scale() const;
		virtual PrimaryType::Vector2 Origin() const;
		virtual PrimaryType::String LabelText() const;
		virtual void Draw(sf::RenderWindow* _window);
#pragma endregion override
	};

}