#pragma region Include
#include <iostream>
#include <string>
#pragma endregion
using namespace std;
#pragma region Variable
//Les ligne et colonnes pour taille des tableau
const int LINE = 7,
COLUMN = 4;

//Le 1er se que va voit le joueur et le second se que le joueur doit voir
string labyrinthe[COLUMN][LINE];
int labyrintheTuile[COLUMN][LINE]=
{
    { 0,0,0,1,3,3,0},
    { 0,0,0,0,0,3,0},
    { 0,0,0,3,3,3,0},
    { 0,0,0,2,0,0,0},
};
//Se qui sera afficher par case
string cell;

//Pour les déplacements
string cursor;
int cursorX = 3,
cursorY = 3;

int player;// Ancienne position du joueur

//Quand le jeu est terminer
bool End = true;

#pragma endregion 
#pragma region Instance methode
void Labyrinthe();
void Cursor();
void Coallision(int _case);
void GameLoop();
void ConditionEnd();
#pragma endregion 
#pragma region Labyrinthe
void Labyrinthe()
{
    
    for (int y = 0; y < COLUMN; y++)
    {
        for (int x = 0; x < LINE; x++)
        {
            //A partir de 'labyrintheTuile' de se quoi doit afficher le labyrinthe
            if (labyrintheTuile[y][x] == 0)
            {
                cell = "#"; //Les murs
            }
            else if (labyrintheTuile[y][x] == 1)
            {
                cell = "S";//La sortie
            }
            else if (labyrintheTuile[y][x] == 2)
            {
                cell = "P";//Le joueur
                
            }
            else if (labyrintheTuile[y][x] == 3)
            {
                cell = " ";//Le chemin vers la sortie
            }
           
 
            labyrinthe[y][x] = cell;
            cout << labyrinthe[y][x];
        }
        cout << endl;
    }
}
#pragma endregion 
#pragma region Cursor
void Cursor()
{
    
    cout << "cursorX[" << cursorX<< "]" << "cursorY[" << cursorY << "]" << endl;
    
    cin >> cursor;
    
    if (cursor == "z" && cursorY > 0)
    {
        cursorY--;//Avance d'en haut le joueur
        player = labyrintheTuile[cursorY][cursorX]; //Prend le chemin ou c'est dirigé le joueur


        labyrintheTuile[cursorY + 1][cursorX] = 3; //ancienne position du joueur '2' dont à la place on a un chemin
        labyrintheTuile[cursorY][cursorX] = 2; //Nouveau emplacement du joueur
        Coallision(1);//Si le joeur fonce contre un mur
       
    }
    else if (cursor == "q" && cursorX > 0)
    {
        cursorX--;
        player = labyrintheTuile[cursorY][cursorX];

        labyrintheTuile[cursorY][cursorX + 1] = 3;
        labyrintheTuile[cursorY][cursorX] = 2;
        Coallision(2);
       
    }
    else if (cursor == "s" && cursorY < COLUMN)
    {
        cursorY++;
        player = labyrintheTuile[cursorY][cursorX];

        labyrintheTuile[cursorY - 1][cursorX] = 3;
        labyrintheTuile[cursorY][cursorX] = 2;
        Coallision(3);
       
    }
    else if (cursor == "d" && cursorX < LINE)
    {
        cursorX++;
        player = labyrintheTuile[cursorY][cursorX];

        labyrintheTuile[cursorY][cursorX - 1] = 3;
        labyrintheTuile[cursorY][cursorX] = 2;
        Coallision(4);
        

    }
    else
    {
        Coallision(5);
        system("CLS");
    }

    ConditionEnd();//Si la condition de fin est respecter on arrête le jeu
    system("CLS");
}
#pragma endregion 
#pragma region Coallision
void Coallision(int _case)
{
    //Les case 1,2,3 et 4 sont lorqu'un joueur fonce dans un mur, 5 si le joeur dépasse la map 
    if (_case == 1)
    {
       

        if (player == 0)
        {
            //Si le joeur fonce dans un mur 
            labyrintheTuile[cursorY][cursorX] = 0; //Endroit initiale du joueur
            cursorY++;
            labyrintheTuile[cursorY][cursorX] = 2; //repositionnement  et affichage du joueur


        }
    }
    if (_case == 2)
    {
      


        if (player == 0)
        {

            labyrintheTuile[cursorY][cursorX] = 0;
            cursorX++;
            labyrintheTuile[cursorY][cursorX] = 2;


        }
    }
    if (_case == 3)
    {
       

        if (player == 0)
        {
            labyrintheTuile[cursorY][cursorX] = 0;
            cursorY--;
            labyrintheTuile[cursorY][cursorX] = 2;


        }
    }
    if (_case == 4)
    {
       

        labyrintheTuile[cursorY][cursorX] = 2;
        if (player == 0)
        {
            labyrintheTuile[cursorY][cursorX] = 0;
            cursorX--;
            labyrintheTuile[cursorY][cursorX] = 2;
        }
    }
    if (_case == 5)
    {
        if (cursorY < 0)
        {

            cursorY == 0;
            labyrintheTuile[cursorY][cursorX] = 2;


        }
        else if (cursorX < 0)
        {

            cursorX = 0;
            labyrintheTuile[cursorY][cursorX] = 2;
        }
        else if (cursorY > 3)
        {

            cursorY = 3;
            labyrintheTuile[cursorY][cursorX] = 2;
        }
        else if (cursorX > LINE)
        {

            cursorX = LINE - 1;
            labyrintheTuile[cursorY][cursorX] = 2;
        }
    }
   
}
#pragma endregion 
#pragma region ConditionEnd
void ConditionEnd()
{
    //Si le joueur arrive vers la même case de la sortie
    if (labyrintheTuile[cursorY][cursorX] == labyrintheTuile[0][3])
    {
        system("CLS");

        End = false;
    }
}
#pragma endregion 
#pragma region GameLoop
void GameLoop()
{
    
    while (End)
    {
        Labyrinthe();
        Cursor();
        
    }
}
#pragma endregion
int main()
{   
    
    GameLoop();
    cout << "WIN" << endl;
}

char** t = new char* [10];
for (int i = 0; < 10; i++)
{
    t[i] = new char(0);
    t[i] = new char[10];
}
delete[] t;