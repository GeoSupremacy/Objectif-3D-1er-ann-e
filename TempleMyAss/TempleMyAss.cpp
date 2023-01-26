#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

const int COLUM(7),
          LINE(6);
string templeMyAss[COLUM][LINE];

string player = "P";
 const int   XPLAYER = (LINE - 1) / 2,
            YPLAYER = COLUM -1 ;
            

string door = "E";
const int xExit = (LINE - 1) / 2,
    yExit = 0;

string cursor;
int cursorX = XPLAYER,
    cursorY = YPLAYER;

string  cell,
        line = "0";
        
        

bool action = true;
void SetColor()
{
   
    if (cell ==line)
    {
        const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 1);
    }
    else if (cell == player)
    {
        const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 4);
    }
    else if (cell == door)
    {
        const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 2);
    }
}

void TempleMyAss()
{
    
   for (int y = 0; y < COLUM; y++)
    {
        for (int x = 0; x < LINE; x++)
        {
            
                cell = line;
                SetColor();
                templeMyAss[y][x] = cell;
                cout << templeMyAss[y][x];
            
                if (x == cursorX && y == cursorY)
                    
                    
                        cell = player;
                        SetColor();
                        templeMyAss[cursorY][cursorX] = cell;
                        cout << templeMyAss[cursorY][cursorX];
                        
                        if (x == xExit && y == yExit)
                            
                                cell = door;
                                SetColor();
                                templeMyAss[yExit][xExit] = cell;
                                cout << templeMyAss[yExit][xExit];
        }
        cout <<  endl;
        
    }
    
        
    
    

}
void SetCursor()
{
       if (cursor == "z")  
       {
           cursorY--;
           cell = player;
           templeMyAss[cursorY][cursorX] = cell;


       }
     else if (cursor == "q")
    {
        cursorX--;
        templeMyAss[cursorY][cursorX] = cell;
        
    }
    else  if (cursor == "s")
    {
        cursorY++;

        templeMyAss[cursorY][cursorX] = cell;
        
    }
    else if (cursor == "d" )
    {
        cursorX = cursorX++;

        templeMyAss[cursorY][cursorX] = cell;
       

    }
    
}
void SetCoalition()
{
    cursor = cursorY < 0 ? cursorY = 0 :
        cursorY > COLUM - 1 ? cursorY = COLUM - 1 :
        cursorX <0 ? cursorX = 0 :
        cursorX > LINE - 1 ? cursorX = LINE - 1 : 0;
}
void GameLoop()
{
    TempleMyAss();

    
    cout << "Cursor P Y " << "["<< cursorY <<"] " << "X[" << cursorX << "]" <<endl;
    std::cin >> cursor;
    system("CLS");


    for (int y = 0; y < COLUM; y++)
    {
        SetCoalition();
        

        for (int x = 0; x < LINE; x++)
        {
            
            SetCursor();
        }
       
    }
    
    
    GameLoop();

}

int main()
{
    
    GameLoop();
}

