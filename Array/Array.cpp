
#include <iostream>
#include <algorithm>                   
using namespace std;
const int idWe(8);
double idW[idWe]{ 0,1,2,3,4,5,6 };

/*
 *  Fonction qui calcule la moyenne des éléments d'un tableau
 *  - tableau : Le tableau dont on veut la moyenne
 *  - tailleTableau : La taille du tableau
 */
double moyenne(double tableau[], int tailleTableau)
{
    double moyenne(0);
    for (int i(0); i < tailleTableau; ++i)
    {
        moyenne += tableau[i];   //On additionne toutes les valeurs
    }
    moyenne /= tailleTableau;

    return moyenne;
}

int main()
{
    
   cout<< moyenne(idW, 5);
}