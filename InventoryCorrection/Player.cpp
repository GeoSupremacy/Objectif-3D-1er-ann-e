#include "Player.h"
#include "Inventory.h"
#include "Utils.h"
#include "Vector2.h"
#include "Case.h"
#include "Map.h"

#pragma region constructor/destructor
Player::Player(const std::string& _name, Vector2* _position, const float _maxLife, const float _maxMana)
    : Entity(_name,_position, _maxLife, _maxMana)
{
    inventory = new Inventory(_name + " Inventory", this);
}

Player::Player(const Player& _copy) : Entity(_copy)
{
    inventory = _copy.inventory;
}

Player::~Player()
{
    delete inventory;
}
#pragma endregion constructor/destructor

#pragma region methods
Inventory* Player::GetInventory() const
{
    return inventory;
}

void Player::Move()
{
    char _input = Utils::UserChoise<char>("z;q;s;d for move: ");
    Vector2 _position = *Position();
    switch (std::tolower(_input))
    {
    case 'z':
        _position -= Vector2(0, 1);
        break;
    case 'q':
        _position -= Vector2(1, 0);
        break;
    case 's':
        _position += Vector2(0, 1);
        break;
    case 'd':
        _position += Vector2(1, 0);
        break;
    default: break;
    }
    Case* _case = GetMap()->GetCaseAtPosition(_position);
    if (_case == nullptr || _case->Iswall()) return;
    Position()->Set(_position);
}

#pragma endregion methods