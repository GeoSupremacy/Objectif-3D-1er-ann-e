#include <iostream>
#include <string>

using namespace std;
int choose;
int youChoose;

void Choose()
{

    cout << "Choisissez un nombre entre 0 et 10:";
    cin >> choose;
    if (choose < 0 || choose > 10)
    {
        cout << "Tu sais lire.... -__-  \n";
        Choose();
    }
    else
    {
        system("CLS");
    }
}
void Start()
{
    cout << "Devine un nombre entre 0 et 10: \n";
    cin >> youChoose;
}

void Play()
{

    if (youChoose > 0 && youChoose < 10)
    {
        if (youChoose != choose)
        {
            if (youChoose == choose - 2)
            {
                cout << "Ah tu t'en rapproche \n";
                Start();
                Play();

            }
            else if (youChoose == choose + 2)
            {
                cout << "Ah tu t'en rapproche \n";
                Start();
                Play();

            }
            else if (youChoose == choose - 1)
            {
                cout << "Ah tu t'en rapproche \n";
                Start();
                Play();

            }
            else if (youChoose == choose + 1)
            {
                cout << "Ah tu t'en rapproche \n";
                Start();
                Play();

            }
            else if (youChoose < choose)
            {
                cout << "C'est plus grand \n";
                Start();
                Play();
            }
            else if (youChoose > choose)
            {
                cout << "C'est plus petit \n";
                Start();
                Play();
            }
        }

        else
        {
            cout << "FELICITATION tu as reussit \n";

        }
    }
    else
    {
        cout << "Tu sais lire...-__- \n";
        Start();
        Play();
    }

}


int main()
{
    Choose();
    Start();
    Play();
    
    
}