#include <iostream>
using namespace std;
void Read();
void Add();
void Clear();

int sizeArray = 0; //Taille par défault!!Toujours
int* table =nullptr; //Le tableau dynamique == pointeur mais se comporte et se définit comme un tableau statique, il est juste très modulable



void Add(int _value)
{
    int* _tmp = table;
    //peter l'ancien tableau  _tmp stock l'ancien
    sizeArray++; //On augmente la taille du tableau de basse rien juste une adreesee
    table = new int[sizeArray]; //Mtn on reset l'ancien en ajoutant une nouvelle occurence de basse occurence '0' valeur 0
    for (size_t i = 0; i < sizeArray-1; i++) //(sizeArray-1) c'est pour l'occurence Au début il n'y a rien mais avt on a ajouter une ocurence
        table[i] = _tmp[i]; // la nouvel table prend l'ancien mais avec ses caractéristiques
    table[sizeArray - 1] = _value; //On ajoute la valeur à la nouvelle ocuurence de base à 0 donc occurence 0 valeur '_value'
}
void Read()
{
    for (size_t i = 0; i < sizeArray; i++)
        cout << table[i] << endl;

    
}
void Clear()
{
    //!!Toujour puisq'on est en freestyle avec le new qui construit et deconstruire donc fuite de mémoire c'est la ou on s'arrête
    //! //Un tableau dynamique et fixe quand on le demande sinon il est tjr en attente d'être modifiable
    sizeArray = 0;
    delete[] table;
}

int main()
{
    Add(5);
    Add(5);
    Add(5);
    Read();
    Clear();
    
}


