#include "B.h"
#include <iostream>

void B::Start()
{
    static int c = 0;
    while(c == 0)
    {
        std::cout << "AHHHHHHH" << std::endl;
        c++;
    }
}
