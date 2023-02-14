#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>

class FB_Score :public Object
{
#pragma region f/p
private:
	Window* owner = nullptr;
	int score = 0;
	class FB_Label* scoreText = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_Score(Window* owner);
	virtual ~FB_Score() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	int CurrentScore() const;
	void UpDateScore();
	void Draw(class Winfpw* _window);
	void SetPosition(const sf::Vector2f& _position);
	void Reset();
#pragma endregion methods
};

