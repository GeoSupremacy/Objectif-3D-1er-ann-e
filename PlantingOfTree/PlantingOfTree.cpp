#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int const   LINE(4),
COLUMN(3);



int cursorX,
cursorY;

string cursor;


int Groundwork[COLUMN][LINE] = 
{
    {1,1,1,3},
    {1,2,1,1},
    {1,0,4,1},
};

string land[COLUMN][LINE];

string cell;

void Land();
void SetLand();
void Cursor();
void Move();
void GameLoop();
void EndGame();

void SetCursor()
{
    cursor = cursor == "z" ? cursorY-- : cursorY;
    cursor = cursor == "q" ? cursorX-- : cursorX;
    cursor = cursor == "s" ? cursorY++ : cursorY;
    cursor = cursor == "d" ? cursorY++ : cursorY;
}

void Move()
{
    
    cout << "Cursor P " << "Y[" << cursorY << "] " << "X[" << cursorX << "]" << endl;
    std::cin >> cursor;
    system("CLS");

    for (int y = 0; y < COLUMN; y++)
    {
        for (int x = 0; x < LINE; x++)
        {
           
            SetCursor();
            cell = "P";
            
        }
    }
}

void SetLand()
{
    for (int y = 0; y < COLUMN; y++)
    {
        for (int x = 0; x < LINE; x++)
        {
            //SetLand();

            if (Groundwork[y][x] == 1 )
            {
                cell = "X";
            }
            else if (Groundwork[y][x] == 2 )
            {
                cell = "A";
            }
            else if (Groundwork[y][x] == 3)
            {
                cell = "C";
            }
            else if (Groundwork[y][x] == 4)
            {
              
                cursorX = x;
                cursorY = y;

                cell = "P";
            }

            else
            {
                cell = "0";
            }
            
            land[y][x] = cell;
            cout << land[y][x];
        }
        cout << endl;
    }
}
void GameLoop()
{
    SetLand();
    while (true)
    {
        Move();
        
    }
}
int main()
{
    GameLoop();
}

