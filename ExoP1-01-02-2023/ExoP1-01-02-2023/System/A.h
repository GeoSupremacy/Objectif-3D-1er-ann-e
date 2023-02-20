#pragma once
#include "B.h"
#include <string>


class A
{
private:
    B * bahDommage = new B();
    std::string str = "";
    int* tab = new int[400];
    float sabug = 0.0f;
public:
    ~A();
    void Test();
    void Hello();
};
