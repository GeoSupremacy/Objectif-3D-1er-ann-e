#pragma once
#include "GameObject.h"
#include "Delegate.h"

#define BIRD_SCALE 0.15f
#define GRAVITY 0.5f
#define BIRD_SPEED_GRAVITY 350


class FB_Bird : public GameObject
{
#pragma region f/p
private:
	bool isDead = false;
	sf::Clock lastJumpTimer = sf::Clock();
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
public:
	Delegate<void> OnDie = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_Bird();
	virtual ~FB_Bird() override;
#pragma endregion constructor/destructor
#pragma region methods
public:

#pragma endregion methods
#pragma region override
public:
	void Die();
	void OnUpdate() override;
	virtual void OnCollissionEnter(GameObject* _other);
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
#pragma endregion override
};


