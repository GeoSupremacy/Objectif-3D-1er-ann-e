#pragma once
#include "GameObject.h"
#include "Delegate.h"

#define SPEED_PIPE 250.0f


class FB_Pipe :public GameObject
{
#pragma region f/p
private:
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
	bool passeBird = false;
public:
	Delegate<void> OnBirdPosition = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_Pipe();
	~FB_Pipe() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Rotate();
	void Move();
	void SetPosition(const sf::Vector2f& _position);
#pragma endregion methods
#pragma region override
public:
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
	virtual void OnUpdate() override;
#pragma endregion override

};

