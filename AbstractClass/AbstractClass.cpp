#include <iostream>
#include "AbstractClass.h"
#include "AbstractClass.h"
#include "IFly.h"
#include "Bird.h"
#include <vector>
int main()
{
    std::vector< AbstractClass*> abstracts = {};
    AbstractClass a;

    IFly* _fly = new Bird();
}

