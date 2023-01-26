#include <iostream>
#include "Array.h"

int main()
{    
    Array<int> _tab1 = Array<int>(10);
    _tab1.GetAt(0, 1);
    _tab1.GetAt(1, 2);
    _tab1.GetAt(2, 3);
    _tab1.Display();
    _tab1.DeleteAt(2);
    _tab1.Display();
}