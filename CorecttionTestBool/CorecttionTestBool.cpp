#include <iostream>

using namespace std;
int guessNumber = 1,
minGuess = 1,
maxGuess = 100;

void SetGuessNumber(int _min, int _max)
{
    cout << "Set number between: " << _min << " and " << _max << " : ";
    cin >> guessNumber;
    if (guessNumber < _min)
        guessNumber = _min;
    else if (guessNumber > _max)
        guessNumber = _max;
    system("CLS");
}

void GuessGame()
{
    cout << "Set number between: " << minGuess << " and " << maxGuess << " : ";

    int  _guess = 0;
    cin >> _guess;
    cout << "Your input is : " << _guess << endl;
    if (_guess == guessNumber)
    {
        cout << "YOU WIN" << _guess << endl;
        SetGuessNumber(minGuess, maxGuess);
        GuessGame();
    }
    else if (_guess > guessNumber)
    {
        cout << "you lose too little";
        SetGuessNumber(minGuess, maxGuess);
        GuessGame();
    }
    else
        cout << "you lose too hight";
    SetGuessNumber(minGuess, maxGuess);
    GuessGame();
}
int main()
{

    SetGuessNumber(minGuess, maxGuess);
    GuessGame();

}


