#include <iostream>
using namespace std;

#pragma region DemandNumber

    int numMin,
        numMax,
        numDevine;
    void ChooseNumber()
    { 
        cout << "Chosse devine between first number and second number \n";
        cout << "first number \n";
        cin >> numMin;
        cout << "Second number \n";
        cin >> numMax;
        cout << "Now  demande number between " << numMin <<" and " << numMax <<" for other player: ";
        cin >> numDevine;
        if (numDevine < numMin  || numDevine > numMax)
        {
            cout << "Bro don't cheat please :) \n";
            ChooseNumber();
        }
        else
        {
            system("CLS");
        }
        
    }

    void Devine(int _numMin, int _numMax)
    {
        int result;
  
        cout << "devine between " << _numMin << " number and " << _numMax << ": ";
        cin >> result;

        if (result < numMin || result > numMax)
        {
            cout << "Seriously, can you read? \n";
            Devine(numMin, numMax);
        }
        else
        {
       
            if (result == numDevine - 1)
            {
                cout << "Oh you are getting closer \n";
                Devine(numMin, numMax);
            }
            else if (result == numDevine + 1)
            {
                cout << "Oh you are getting closer! \n";
                Devine(numMin, numMax);
            }
            else if (result < numDevine)
            {
                cout << "It's bigger \n";
                Devine(numMin, numMax);
            }
            else if (result > numDevine)
            {
                cout << "It's smaller \n";
                Devine(numMin, numMax);
            }
            else if (result == numDevine)
            {
                cout << "CONGRATULATIONS YOU WIN!!";
            }
        }
    }

#pragma endregion

int main()
{
  ChooseNumber();
  Devine(numMin, numMax);
}

