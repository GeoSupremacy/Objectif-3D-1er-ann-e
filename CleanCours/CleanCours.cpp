#include <iostream>
#include "Example.Child"

int main()
{
    Example ex = Example();
    Example ex1  = ex;
    ex==ex1;
}

