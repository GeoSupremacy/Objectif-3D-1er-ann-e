#include <iostream>

using namespace std;

/*
* 1 - Convertir des valeurs
* 2 - Programmer les formules de convertions
* 3 - m-> feet
* 4 - cin /out - choisir le mode 2 entrer la valeur
* 5 result
*/

float GetFeetFromMeter(float _meter)
    {
    return _meter * 3.28f;
    }

float GetFeetFromFeet(float _feet)
{
    return _feet / 3.28f;
}

float GetKmhFromKts(float _feet)
{
    return _feet * 1.852f;
}
float GetKtsFromKmh(float _feet)
{
    return _feet / 1.852f;
}

int main()
{
    cout << GetFeetFromMeter(1);
    cout << GetFeetFromFeet(1);
    cout << GetKmhFromKts(1);
    cout << GetKtsFromKmh(1);

}


