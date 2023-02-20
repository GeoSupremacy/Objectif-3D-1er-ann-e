#include "A.h"
#include <iostream>


A::~A()
{
   delete bahDommage;
    bahDommage = nullptr;
}
void A::Test()
{
    
    bahDommage->Start();
}
void A::Hello()
{
    std::cout << "Hello" << std::endl;
    
}
