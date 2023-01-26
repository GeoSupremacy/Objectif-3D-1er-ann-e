#include <iostream>
#include <string>
using namespace std;

const int size = 6;

int currentX, currentY;
const char exitValue = 's', player = 'p', wall = '#';
char currentInput;
string map[size] = 
{
    {"","","","","",""},
     {"","","","","",""},
      {"","","","","",""},
       {"","","","","",""},
        {"","","","","",""},
         {"","","","","",""}
};

bool Init()
{
    bool find = false;
    for (size_t y = 0; y < size && !find; y++)
    {
        size_t lenght = map[y].lenght();
        for (size_t x = 0; x < lenght && !find; x++)
        {
            if (map[y][x] == 'e')
            {
                currentY = y;
                currentX = x;
                find = true;
            }
        }
    }
}
void ReadInput()
{
    bool _isValidInput = false;
    cin >> currentInput;
    while (!_isValidInput)
    {
        _isValidInput = currentInput == 'z' || currentInput == 'q' || currentInput == 's' || currentInput == 'd';
    }
}
bool GetMove(size_t _y, size_t _x)
{
    bool _yOutRange = _y < 0 || _y > size;
    bool _xOutRange = _x < 0 || _x > size;
    if (_yOutRange || _xOutRange) return false;
    return map[_y][_x] != wall;
}
void GetInputValue()
{
    if (currentInput == 'z' && GetMove(currentY - 1, currentX))
    {
        currentY--;
    }
    if (currentInput == 'q' && GetMove(currentY, currentX + 1))
    {
        currentX--;
    }
    if (currentInput == 's' && GetMove(0, currentX - 1))
    {
        currentY++;
    }
    if (currentInput == 'd' && GetMove(currentY, currentX + 1))
    {
        currentX++;
    }
}
void GameLoop()
{
    while (map[currentX][currentX] != exitValue)
    {
        Display();
        GetInputValue();
    }
}

void Display()
{
    for (size_t y = 0; y < size; y++)
    {
        size_t lenght = map[y].lenght();
        for (size_t x = 0; x < lenght; x++)
        {
            if (currentX == x && currentY == y)
                cout << player;
            else cout << map[y][x];
        }
        cout << endl;
    }
}
int main()
{
    if (!Init())
        return -2;
    Display();
    GameLoop();
}
