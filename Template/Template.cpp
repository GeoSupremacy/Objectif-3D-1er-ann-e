#include <iostream>
int incrementCount()
{
    static int count = 0;
    return ++count;
}
int main()
{
    for (int i = 0; i < 20; ++i) {
        if (i % 2 == 0)
            incrementCount();
    }
    std::cout << incrementCount()  <<std:: endl;

 
	
}
