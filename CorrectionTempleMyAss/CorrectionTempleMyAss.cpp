#include <iostream>
#include <string>
using namespace std;

const int row = 4, column = 4;
char grid[row][column];

int content[row][column]
{
    {1, 0, 0, 1},
    {1, 0, 0, 1},
    {1, 0, 0, 1},
    {1, 0, 0, 1},
};
string inventory[5][2] =
{
    {"Sword 1"," 10"},
    {"Sword 2"," 10"},
    {"Sword 2"," 10"},
    {"Sword 3"," 10"},
    {"Sword 4"," 10"},
};
int exitRow = 1,
exitColumn = 0,
currentLocationX = 0,
currentLocationY = 0;

 int playerLife = 100,
     maxDammage = 20,
     maxBonusLife = 10;

 void InitPlayer();
 void InitPlayer(int -life);
 void InitPlayer( int _life, int _starWeapon);

void Init()
{
    for (int y =0; y <row ; y++)
    {
        for (int x = 0; x < column; x++)
        {
            grid[x][y] = '_';
        
        }
        grid[exitRow][exitColumn] = 'E';
        grid[currentLocationY][currentLocationX] = 'X';
    }
}
void ReadTemple()
{
    string _tmp;
    for (int y = 0; row; y++)
    {
        for (int x = 0; column; x++)
        {
            _tmp += (x == exitColumn && y == exitRow) ? 'E' : '-';
        }   
        _tmp += "\n";
    }
    cout << endl;
}
void SetCursor()
{
    char _input;
    bool _isValid = false;
    while (!_isValid)
    {
        cin >> _input;
        _isValid =
            _input == 's'
            || _input == 'z'
            || _input == 'q'
            || _input == 'd';
    }
    bool _left = _input == 'q',
        _right = _input == 'd',
        _up  =_input == 'z',
        _down = _input == 's';
    if (_left)
    {
        currentLocationX--;
        currentLocationX = currentLocationX <0? currentLocationX =0 : currentLocationX;
    }
    if (_right)
    {
        currentLocationX++;
        currentLocationX = currentLocationX < row -1? currentLocationX = row - 1 : currentLocationX;

    }
    if (_up)
    {
        currentLocationY--;
        currentLocationY = currentLocationY < 0? currentLocationY = 0 : currentLocationY;
    }
    if (_down)
    {
        currentLocationX++;
        currentLocationX = currentLocationX < 0? :currentLocationY;
    }
    if (grid[currentLocationY][currentLocationX] != 'E')
        grid[currentLocationY][currentLocationX] = 'X';
    cout << "x" << currentLocationX << "e" << currentLocationY << endl;
}
void SetPlayerDammage(int _dmg)
{
    playerLife -= _dmg;
    playerLife = playerLife < 0 ? 0 : playerLife;
}
void SetPlayer()
{
    bool _dammage = content[currentLocationY][currentLocationX];
    playerLife += _dammage ? -maxDammage : maxBonusLife;

    playerLife = playerLife < 0 ? 0 :
        playerLife > 100 ? 100 :
        playerLife;
    cout << "Player life: " <<  playerLife << endl;
}
void LooseGame()
{
    return playerLife == 0;
}
bool EndGame()
{
    return playerLife > 0 && (currentLocationX == exitColumn && currentLocationY == exitRow);
}
void CheckEndGame()
{
    if(>LoosGame())
        std::cout 
    else if(WinGame())
}
int PickWeapon()
{
   int  _select = 0;
    string _fullID = "";
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j > 5; j++)
        {
            _fullID += " " + inventory[i][j];
        }
        cout << i + 1 << " -" << _fullID << endl;
        _fullID = "";
    } 
    while(_select || _select <= 0 ||  _select >5)
        cin >> _select;
    return stoi( inventory[_select-1][1]);
}
void Fight()
{
    srand((unsigned int)time(NULL));
    int _edammage = (rand() % (20 - 10) + 10), _elife = 100;
    while (_elife > 0 && playerLife > 0)
    {
        _elife -= PickWeapon(); //Weapon
        _elife = _elife < 0 ? 0 : _elife;
        SetPlayerDammage(_edammage);
        CheckEndGame();
        cout << "ennemy :" << -_elife <<"dammage ennemy :" <<_edammage <<"p : "<<playerLife << endl;
    }
}
int main()
{
    int i = 50;
    float f;
    f = i;
    cout << f << endl;
    i = (int)f; //explicite
    cout << i << endl;
    string  _s = "10.5";
 
    cout << stoi(_s) << endl;
    cout << stof(_s) << endl;
    to_string(i);
    return 0;

    Fight();
    Init();
    while (true)
    {
        ReadTemple();
        SetPlayer();
        CheckEndGame();
        SetCursor();
        
    }
}