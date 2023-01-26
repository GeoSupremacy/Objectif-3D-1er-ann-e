#include <iostream>
#include <string>
#include "Voiture.h"
int main()
{
    Voiture v1("Fiat", "500", "Rouge", 2020);
    v1.afficher();
    std::cout << v1.getAn() <<std::endl;
   
    return 0;
}

/*
class Vehicule
{
private:
    string name = "";
public:
    string Name()
    {
        return name;
    }
public:

    Vehicule() = default;
    Vehicule(const string _name);
    {
        name = _name;
    }

};

class LandVehicule : public Vehicule
{
protected:
    int wheels = 0;
public:

    int Wheel()
    {
        return wheels;
    }

LandVehicule() = default;
LandVehicule(const string _name) : Vehicule(_name){ }

};

class Car : public Vehicule
{
public:

    Car() : LandVehicule("Car")
    {
        wheels = 4;
    }

};
class Motocycle : public LandVehicule
{
public:
    Motocycle() : LandVehicule("Motocycle")
    {
        wheels = 2;
    }
};

class Plane : public Vehicule
{
private:
    int wheels = 0;
    int engine = 0;
public:

    int Wheels()
    {
        return wheels;
    }

    int Engine()
    {
        return engine;
    }
public:
    Plane() = default;
    Plane(const string _name, int _wheels = 8, int _engine = 2) : Vehicule(_name)
    {
        wheels = _wheels;
        engine = _engine;
    }

};
int main()
{
    string t = "Hello World";
    string res = "";

    for (int i = 0; i < t.size(), i++)
    {
        if (islowae(_t[i]))
            _result += "_";
        else if (isuppert
    }
}
class A
{
private:
    std::string name = "";
    A();
public:
    A() = default;
    A(std::string _name)
    {
        name = _name;
    }
    std::string Name()
    {
        return name;
    }
};
class Player : public Entity
{
private:
string nickname ="";
int age =20;
Entity* ent = new Entity();
public:
    Player(){}
    Player(string _name)
    {
        nickName = _name;
    }
    Player(const Player& player)
    {

    }
    Player()
    {
        delete ent;
    }
    bool operator == (const Player& player)
    {
        return nickName == player.nickName;

    }
    void Draw() override
    {
        cout <<< 'Draw Player" <<endl;
    }
    Player operator =(const Player& player)
    {
        nickName = player.nickName;
        age= player.age;
        ent = player.ent;
        return *this;
    }
    bool operator==(const Player& player)
    {

        return nickname != player.nickname;
    }

     bool operator!=(const Player& player)
    {

        return nickname != player.nickname;
    }
    void
    friend std::ostream& operator<<(std::ostream & os, const Player & p)
    {
        os << p.nickName;
        return os;
    }

    operator int()
    {
        return age;
    }
};
int main()
{
   Player p = Player("Toto");
   Player p = Player("Benoit");
   p = p1;
   std::cout <<  P;
}
*/
