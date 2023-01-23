#include <iostream>
#include<format>
#include "Object.h"
#include "IGame.h"


#define USER "Thomas"

#define nameof(x) #x //'#' pour le nom
#define Add(a, b) a +b;
#define PURE_VIRTUAL() = 0;
#define null nullptr;

void Display(Object _o)
{
    std::cout << std::format("Is Interface: {}\n", _o->IsInterface());
    std::cout << std::format("Is Class: {}\n", _o->IsInterface());
    std::cout << std::format("Is Abstract: {}\n", _o->IsInterface());
    std::cout << "\n\n";
}

int main()
{
    Object* game = new Object();
    Display(game);

    IGame* game1 = new IGame();
    Display(game1);

    o->GetParentClss
    return 0;
}
#pragma region Macro
/*--------------------
* Object o;
    o.SetBitMask(Interface);
    Display(o);
    Object o1;
    o1.SetBitMask(Abstract);
    Display(o1);
* -----------------
* #define USER "Thomas"
#define nameof(x) #x //'#' pour le nom
#define Add(a, b) a +b;
#define PURE_VIRTUAL() = 0;
#define null nullptr;

class A
{
public:
    virtual void Test() PURE_VIRTUAL()
};
*  int a = 0;

    A* _a = null;
    std::cout << nameof(a);
    std::cout << Add(5, 10);
-----------------------
std::cout << nameof(a);
* 
    ;*/
#pragma endregion Macro
#pragma region example
/*
* #include <iostream>
#include <vector>
#include "Object.h"
#include "Action.h"
* class A : public Object
{
public:
    

    void Test(float _a )
    {
        std::cout << _a <<std::endl;
    }
    
    void Hello(float _b)
    {
        std::cout << "Hello: " << _b << std::endl;
    }
};
void OnEnd(Object* _instance, Action<float> _callback)
{
    _callback.Invoke(_instance, 5.0f);
}
A _a = A();
    Action<float>OnUpdate = &A::Test;

    try
    {
        OnUpdate.Invoke(&_a, 5.0f);
    }
    catch (const Exception& _e)
    {
        std::cout << _e.ToString();
    }
    return 0;
* ----------------------
* A* _a =  A();
    Action<float>OnUpdate =nullptr;
    Action<const std::string&, float>OnUpdate1 = &A::Hello;

    OnUpdate.Invoke(&_a, 5.0f);
    OnUpdate1.Invoke(&_a, "Hello Kitty: ", 5.0f);
    
  
    return 0;

------------
*  A* _a = new A();
*  OnUpdate.Invoke(_a, 1);

    OnUpdate -= &A::Test;

    OnUpdate.Invoke(_a, 2);

    OnUpdate += &A::Test;

    OnUpdate.Invoke(_a, 3);

    OnUpdate += &A::Hello;

    OnUpdate.Invoke(_a, 5);

    OnUpdate = nullptr;

    OnUpdate.Invoke(_a, 10);
    delete _a; 
    Func<int> OnAdd = &A::Add;
    const int _result = OnAdd.Invoke(5, 10);
    ------------
class B : public  A
{
public:
    void Test(int _a)
    {
        std::cout << _a << std::endl;
    }
};
template <typename T>
class K: public  A
{
public:
    void Test(T _a)
    {
        std::cout << _a << std::endl;
    }
};


std::vector<float> Action = {5.0f};
template <typename T>
 void(*OnUpdate)(const T&);
  OnUpdate += &A::Add;
     OnUpdate += &B::Test;
     OnUpdate += &K::TaMere;
     OnUpdate.Invoke(instance, 5.0f);//template '5.0f'

     OnUpdate -= &A::Add;

     OnUpdate = &A::Add;
     OnUpdate -= nullptr;*/
#pragma endregion example