#include "Array.h"



int main()
{
    Array<int> _tab1 = Array<int>(10);
    _tab1.GetAt(0) = 100;
    _tab1.GetAt(1) = 100;
    _tab1.GetAt(2) = 100;
    _tab1.GetAt(3) = 100;
    _tab1.GetAt(4) = 100;
    _tab1.GetAt(5) = 100;
    _tab1.Display();
}