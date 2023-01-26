#pragma once
#include "Entity.h"
#include "Vector2.h"

class Inventory;

class Player : public Entity
{
#pragma region f/p
private:
	Inventory* inventory = nullptr;
	
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Player() = default;
	Player(const std::string& _name, Vector2* _position = new Vector2(0,0), const float _maxLife = 100.0f, const float _maxMana = 100.0f);
	Player(const Player& _copy);
	~Player();
#pragma endregion constructor/destructor
#pragma region methods
public:
	Inventory* GetInventory() const;
	void Move() override;
#pragma endregion methods
};

