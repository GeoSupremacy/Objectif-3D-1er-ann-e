#include <iostream>
#include "List/List.h"

int main()
{
    List<int> A;
    std::cout <<"Is 1, not empty! "<<A.Contain()<< std::endl;
    A.Add(0);
    A.Add(1);
    A.Add(2);
    A.Add(3);
    A.Add(4);
    A.Add(5);
    std::cout << "Is 1, not empty! " << A.Contain() << std::endl;


    A.ReadAll();
    A.Remove(6);
    A.Remove(4);
    A.ReadAll();

    A.AddAt(7, 8);
    A.AddAt(7, 3);
    A.ReadAll();
    A.Clear();
    std::cout << std::endl;


    List<float> B;
    B.AddAt(7.05f, 8);
    B.ReadAll();
    return 0;
}