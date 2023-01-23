#include <iostream>

void Display(const std::string& _msg)
{
    std::cout << _msg << std::endl;
}
class A
{
public:
    void HelloKitty()
    {
        std::cout << "Hello kitty" << std::endl;
    }

    int Add(const int _a, const int _b)
    {
        return _a + _b;
    }
};
class B : public  A
{
public:
    void Test()
    {
        std::cout << "Hello B" << std::endl;
    }
};
int main()
{
    /*void(*ptr) (const std::string&);
    //ptr = &Display;
    //ptr("h1");
    -------------------
    void(A::*ptr)();
    ptr = &A::HelloKitty;
    A* a = new A();
    (a->*ptr)();
    ---------------------
    A* a = new A();
    int(A:: * ptr)(const int, const int);
    ptr = &A::Add;
    std::cout << (a->*ptr)(10, 5);
    ------------------------------
      B* b = new B();
    void(A:: * ptr)();
    ptr = reinterpret_cast<void(A::*)()>(&B::Test);
    (b->*ptr)();
    ------------------------------------
       A* a = new A();
    typedef void(A::* Function)();

    Function _function = &A::HelloKitty;
    (a->*_function)();
    */
 
    Action<float>OnUpdate = nullptr || &A::Add;
    OnUpdate += &A::Add;
    OnUpdate += &B::Test;
    OnUpdate += &K::TaMere;
    OnUpdate.Invoke(instance,5.0f);

    OnUpdate -= &A::Add;

    OnUpdate = &A::Add;
    OnUpdate -= nullptr;
    return 0;
}

