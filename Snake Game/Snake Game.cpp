#include <iostream>
#include <vector>
std::string snake = "O";
std::string cell = "#";
int positionX, positionY;
void Board(const int _size)
{
    std::string _cell;
    for (int i = 0; i < _size; i++)
    {

        for (int j = 0; j < _size; j++)
        {
            positionX = _size / 2;
            positionY = positionX;
            if (i == positionX && j == positionX)
            {
                 _cell = snake;
                std::cout << _cell;
                
            }
             if (j == 0 || j == _size-1)
            {
                _cell = cell;
                std::cout << _cell;
            }
            else if (i == 0 || i == _size-1)
            {
                _cell = cell;
                std::cout << _cell;
            }
            else
            {
                 std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
void Snake(int _positionX,int _PositionY)
{
    
}
int main()
{
    Board(20);
    
}

#pragma region Test
/*
* 8
*/

#pragma endregion Test