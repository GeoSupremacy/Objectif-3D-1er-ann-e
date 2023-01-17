#include <iostream>
#include <string>
#include "Sister.h"

int main()
{
   
    int _a = 5;

     std::cout << _a;
    return 0;
}
#pragma region List
/*
* void InitLog();
    Log("Hello");
* void Log(const char* message);
void InitLog();
void InitLog()
{
    Log("Initializing");
}
void Log(const char* message)
{
    std::cout << message << std::endl;
}
class List
{
private:
    int size;
    int index;
    int* list;
public:
    List() = default;
    List(int _size, int* _list)
    {
        this->size = _size;
        this->list = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            this->list[i] = _list[i];

            std::cout << "list[" << i << "]" << list[i] << std::endl;
        }
        std::cout << std::endl;
    }

    void getAt(int _index)
    {

        std::cout << "Index: " << list[_index] << std::endl;
    }
    int getFront();
    int getBack(int _index);

};
*/
#pragma endregion List
