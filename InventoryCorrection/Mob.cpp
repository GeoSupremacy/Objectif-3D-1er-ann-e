#include "Mob.h"
#include "Utils.h"
#include "Case.h"
#include "Map.h"


Mob::Mob(const std::string& _name, Vector2* _position, const float _maxLife, const float _maxMana)
    : Entity(_name, _position, _maxLife, _maxMana)
{}

Mob::Mob(const Mob& _copy) : Entity(_copy)
{}

void Mob::Move() // Déplacement du mob est un rand à 4 valeur où chaque valeur est un input //
{
    srand((unsigned int)time(NULL));

    int _input = rand() % 4;
    Vector2 _position = *Position();

    switch (_input)
    {
    case 0:
        _position -= Vector2(0, 1);
        break;

    case 1:
        _position -= Vector2(1, 0);
        break;

    case 2:
        _position += Vector2(0, 1);
        break;

    case 3:
        _position += Vector2(1, 0);
        break;


    default:
        break;
    }

    Case* _case = GetMap()->GetCaseAtPosition(_position);
    if (_case == nullptr || _case->IsWall()) return;

    //Position()->SetX(_position);
}

#pragma region OldMob
/*
* #include <stdlib.h>
Mob(const std::string& _name, Vector2* _position = new Vector2(0, 0), const float _maxLife = 100.0f, const float _maxMana = 100.0f) 
    : Entity(_name, _position, _maxLife, _maxMana)
{
    position = _position;
}
Mob::Mob(const Mob& _copy)
{
    
}
Mob::~Mob()
{
    delete position;
}
void Mob::Move()
{
    //Après le chargement le mob se déplace veticalement ou horizontalement
    bool _move;
    int _statenumber;
    //Move sert à dire que le mob ne peut que se déplacer que verticalement ou horizontalement
    switch (!_move)
    {
    case false:
        _move = true;
        _statenumber = rand() % 2;
        break;
    case true:
        break;
    }
    
    
    Vector2 _position = *Position();
    Case* _case = GetMap()->GetCaseAtPosition(_position);
    int _walk, _velocity = 1; // '_velocity' sert pour que le mob change de direction
    //Sinon move sert aussi pour que le mob bouge tant qu'il n'est pas mort
    while (_move)
    {
        if (Entity::IsDead())
            _move = false;
        switch (_statenumber)
        {
        case 1:
            _walk = _walk + _velocity;
            _position = Vector2(0, _walk);
            if (_case == nullptr || _case->Iswall())
            {
                _velocity = 0 - _velocity;
                return;
            }
            Position()->Set(_position);
            break;
        case 2:
            _walk = _walk + _velocity;
            _position = Vector2(_walk, 0);
            if (_case == nullptr || _case->Iswall())
            {
                _velocity = 0 - _velocity;
                return;
            }
            Position()->Set(_position);
            break;
        }
        
        
    }
}*/
#pragma endregion
