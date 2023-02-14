#pragma once
#include <SFML\Graphics.hpp>
#include "Object.h"


class Window;

class FB_UIElement :public Object
{
#pragma region f/p
protected:
	bool isActive = false;
	Window* owner = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_UIElement() = default;
	FB_UIElement(Window* _owner);
	FB_UIElement(const FB_UIElement& _copy);
#pragma endregion constructor/destructor
#pragma region methods
public:
	virtual void SetPosition(const sf::Vector2f& _position) = 0;
	virtual void SetScale(const sf::Vector2f& _scale) = 0;
	virtual void Draw(class Window* _window) = 0;
	virtual void SetOrigin(const sf::Vector2f& _origine) = 0;
	virtual void OnUpdate();
	void SetActive(const bool _statue);
	virtual sf::FloatRect GetGlobalBounds() const;
#pragma endregion methods
};

