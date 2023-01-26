// // (3x 3) tableau
//Tableau vide
//ZQSD curseur
//O X Remplace pis pace autre j
//2j 
// 

#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
int cursorX , cursorY;
string cursor;

const int LINE(3),COLUM(3);

std::string morpion[COLUM][LINE];

std::string  line = "-";


bool touch = true;
bool tabletouch[COLUM][LINE];
     
void Morpion()
{
    cout << "Use z,q,s,d to get around tap any key to draw" <<endl;
    cout << "0" << "-> 1" <<endl;
    cout << "|"   << endl;
    cout << "1" << endl;
    for (int y = 0; y< COLUM; y++)
    {
        
        for (int x = 0; x < LINE; x++)
        {
            if (touch)
            {
                line = "-";
                morpion[y][x] = line;
                std::cout << morpion[y][x];
            }
            else
            {
                if (morpion[y][x] == "-")
                {
                    line = "-";

                    morpion[y][x] = line;
                    std::cout << morpion[y][x];
                }
                else
                {

                    line = "0";
                    morpion[y][x] = line;
                    std::cout << morpion[y][x];
                }
                if (morpion[y][x] == "O" && morpion[y][x + 1] == "O" && morpion[y][x + 2] == "O")
                {

                    cout << "YOU WIN";
                    touch = true;

                    
                }
            }
    
        }
        std::cout << std::endl;
    }
    touch = false;
    
    

}


void Player(string _cursor)
{
    bool playerOne = true,
    playerTwo = true;

    
    std::cin >> _cursor;

    

   
}
void GameLoop()
{
    
    Morpion();


    for (int y = 0; y < COLUM; y++)
    {

        for (int x = 0; x < LINE; x++)
        {
            
            
            if (cursorY < 0)
            {
                cursorY = 0;
            }
            else if (cursorY < COLUM-1)
            {
                cursorY = COLUM-1;
            }
            else if (cursorX < 0)
            {
                cursorX = 1;
            }
           
            else if (cursorX > LINE)
            {
                cursorX = LINE;
            }
           
           

            std::cout << "player " << "morpion [" << cursorY  << "]"<< "[" << cursorX <<"]";
            std::cin >> cursor;
            system("CLS");
           


            if (cursor == "o")
            {
                cursor = "0";
                y = cursorY;
                x = cursorX;
                morpion[y][x] = cursor;
               
                
                
            }
            if (cursor == "z")
            {
                
                cursorY = cursorY +1;
                
                GameLoop();
            }
            else if (cursor == "q")
            {
                cursorX = cursorX - 1;
                
                GameLoop();
            }
            else  if (cursor == "s")
            {
                cursorY = cursorY - 1;
                
                GameLoop();
            }
            else if (cursor == "d")
            {
                cursorX = cursorX + 1;
                
                GameLoop();
            }
            
            
           
            
            

        }
        std::cout << std::endl;
    }
}

int main()
{
    //const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(_hConsole, 1);
    
    GameLoop();
    
    
    
}

