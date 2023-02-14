#pragma once
#include "FB_UIElement.h"


class FB_Label :public FB_UIElement
{
#pragma region f/p
private:
	sf::Text* text = nullptr;
	sf::Font* font = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_Label(Window* _owner, const char* _text);
	~FB_Label() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Free();
public:
	void SetCharactereSize(const int _size);
	void SetColore(const sf::Color& _color);
	void SetText(const char* _text);
public:
	virtual void SetPosition(const sf::Vector2f& _position) override;
	virtual void SetScale(const sf::Vector2f& _scale) override;
	virtual void Draw(class Window* _window) override;
	virtual void SetOrigin(const sf::Vector2f& _origine) override;
#pragma endregion methods
};

