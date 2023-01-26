#include <iostream>
int playerLife = 100;

void Toto();
void First();
void Example(float )

float Last();
float Last(int _a);
float Last(int _a, int _b);

int GetPlayerLife();
int GetPlayerLife(int _dmg);
int GetPlayerLife(int _dmg, int _hour);
int GetPlayerLife(std:: string  _dmg, int _hour);

int DefaultSpec(int _dmg = 1);
//int DefaultSpec(int _dmg = 1, float _other);
int DefaultSpec(int _dmg = 1, float _other) = 2;
//int DefaultSpec(int _dmg , float _other = 2);
/// 
/// 
/// 
/// 
 
int DefaultSpec()
{
    return 2;
}
DefaultSpec(int _dmg)
{
    return _dmg *2;
}

int GetPlayerLife()
{
    return playerLife;
}
int GetPlayerLife(int _dmg)
{
    return _dmg *2;
}
int GetPlayerLife(int _dmg, int _hour);
{
    return _dmg * 2 * _hour;
}

void First()
{
    Toto();
    Example(5.0);
}
void Toto()
{
    return 0;
}
void Example(float _f)
{
    return 0;
}

float Last();
{
    return 0;
}
float Last(int _a);
{
    return 0;
}
float Last(int _a, int _b);
{
    return 0;
}
int main()
{
    Last
}

