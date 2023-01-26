#include<iostream>
using namespace std;

int guessMin = 1,
guessMax = 100,
guess = 0,

currentGuess;

bool IsValidGuess(int _input, int _minGuess, int _maxGuess)
{
    if (_input < _minGuess || _input > _maxGuess)
        return false;
    return true;
}
void SetGuessNumber(int _min, int _max)
{
    cout << "Set number to guess between: " << _min << " and " << _max << endl;
    cin >> guess;
    if (IsValidGuess(guess, guessMin, guessMax) == false)
    {
        SetGuessNumber( guessMin,  guessMax);
    }

}
bool Guess(int _guessInput, int _guessValid)
{
    if (_guessInput == _guessValid)
    {
        return true;
    }
    if (_guessInput > _guessValid)
    {
        cout << "less" << endl;
    }
    if (_guessInput < _guessValid)
    {
        cout << "more" << endl;
    }

}

void MainLoop()
{
    int _currentGuess = 0;
    cin >> _currentGuess;
    if (Guess(guessMin, guessMax) == true)
    {
        cout << "WIN ";
    }
    else
    {
        MainLoop();
    }
}


int main()
{
    SetGuessNumber(guessMin, guessMax);
    MainLoop();
}

