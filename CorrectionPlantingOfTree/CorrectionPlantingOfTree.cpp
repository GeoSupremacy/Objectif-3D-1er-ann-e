#include <iostream>
#include <string>
using namespace std;

const int gardenSize = 3;
int garden[gardenSize][gardenSize];
int currentX = 0, currentY = 0;

void InitGarden();
void ReadGarden(int _garden[gardenSize][gardenSize]);
void SetCursor();
void MovePlayer();
string GetCurserLocation();


string GetCurserLocation()
{
    return to_string(currentX) + to_string(currentY);
}

void SetCursor()
{
    char _input;
    bool _isValid = false;
    while (!_isValid)
    {
        cin >> _input;
        _isValid = _input == 'z' || _input == 'q' || _input == 's' || _input == 'd';

        if (_input == 'z')
        {
            currentY--;
            currentY = currentY < 0 ? 0 : currentY;
        }
        else if (_input == 'q')
        {
            currentX--;
            currentX = currentX < 0 ? 0 : currentX;
        }
        else if (_input == 's')
        {
            currentY++;
            currentY = currentY > gardenSize-1 ? gardenSize - 1 : currentY;
        }
        else if (_input == 'd')
        {
            currentX++;
            currentX = currentX > gardenSize - 1 ? gardenSize - 1 : currentY;
        }
        cout << GetCurserLocation() << endl;
    }
}
void MovePlayer()
{
    char _result = garden[currentY][currentX];
    garden[currentY][currentX] = _result == 1 ? 0 : 1;
    cout << garden[currentY][currentX] <<endl;
}
void InitGarden()
{
    srand((unsigned int)time(NULL));
    int _edammage = (rand() % (20 - 10) + 10), _elife = 100;
    string _tmp = "";
    for (int i = 0; i < gardenSize; i++)
    {
        for (int j = 0; j < gardenSize; j++)
        {
         _tmp = garden[j][i] = rand()%2;
        }
        
    }
   
}
void ReadGarden(int _garden[gardenSize][gardenSize])
{
    
    string _tmp;
   
    for (int i = 0; i < gardenSize; i++)
    {
        for (int j = 0; j < gardenSize; j++)
        {
            _tmp += _garden[i][j] == 1 ? "A" : "C";
        }
        _tmp += "\n";
    }
    std::cout << _tmp <<endl;
}
int main()
{

    InitGarden();
    while (true)
    {
        ReadGarden(garden);
        SetCursor();
        MovePlayer();
    }

}

