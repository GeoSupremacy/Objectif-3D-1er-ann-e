//Adress principe de l'objet puis sa philosophie
#include <iostream>
/*
void DynamiqueTable(int _i)
{
    int* table[_i] = { 1,6,5,9,7,8 };
    //int* _tableInt = new int[_i];
    for (size_t i = 0; i < _i; i++)
    {

        cout << i <<endl;

    }


}*/
/*
int a = 5, b = 6, c = 10;

int *ptrA = nullptr;
int *ptrB =&b;
const int* PTRB = ptrB;
int Example()
{
    int* _a = new int(54);
    int _b = *_a;
    delete _a;
    //return _a;
    return _b;
}
void SwapAB(int *_a, int *_b)
{
    // Modife valeur a
    int _tmp = *_a;
    *_a = *_b;

    std::cout << " a " << a  << "  " << "b " << b << std::endl;
    std::cout << " adresse a " << &a << "  " << " adresse b " << &b << std::endl;
}
void New()
{
    //int* _i (int*)malloc(sizeof(15));
   // free(_i);
    //Nouvelle adresse à chaque relançement du programme
    int* _integer = new int(5); //!!!!! ATTENTION FUITE DE MEMOIRE!!!! !!!!!! new ==dele de l'objet préexixtant DONC ON L'aloue!!!!
    cout << "_integer" << _integer << std::endl;
    cout << "*_integer" << *_integer << std::endl;
    *_integer = 100;
    cout << "_integer =100 " << _integer << std::endl;
    cout << "*_integer =100 " << *_integer << std::endl;
    delete _integer;

}
void Valeur()
{

    int _b = 10;
    std::cout << "&b " << &b<< std::endl;
    std::cout << "&a " << &a <<" a"<< a<< std::endl;
    a = _b;
}
void InitatePtr()
{
    std::cout << "Teste adresse " << std::endl;
    std::cout << "&ptrA " << &ptrA << std::endl;
    //std::cout << "a " << *ptrA << std::endl;  Because Exception thrown: read access violation.  ptrA was nullptr(#).
    std::cout << "ptrA " << ptrA << std::endl;// valeur?
    std::cout << std::endl;

    std::cout << "Teste adresse d'une valeur " << std::endl;
    std::cout << "a " << a << std::endl; //valeur
    std::cout << "&a " << &a << std::endl; // '&' c'est l'adresse dela variable 'a'
    std::cout << std::endl;

    std::cout << "ptrA prend l'adresse de a mais aussi sa valeur " << std::endl;
    ptrA = &a;
    std::cout << "ptrA = &a " << ptrA << std::endl;
    std::cout << "*ptrA " << *ptrA << std::endl;//ptrA prend l'adresse de a mais aussi sa valeur l'erreur (#) ne s'affiche plus
    std::cout << std::endl;

    std::cout << "ptrA reprend 0 " << std::endl;
    ptrA = 0;
    std::cout << "ptrA " << ptrA << std::endl;
    std::cout << "&ptrA " << &ptrA << std::endl; //Garde l'adresse de a  mais change sa valeur
    std::cout << "Donc a ? " << a << std::endl;
    std::cout << "l'adresse de a ? " << &a << std::endl; // Donc une adresse peut avoir plusieur valeur
    std::cout << std::endl;

    std::cout << "a et b on une adresse différente " << std::endl;
    std::cout << "a& " << &a << " b& " << &b << std::endl;
    SwapAB(&a, &b); //L'adresse reste le même mais a à la même  valeur que b, donc grâce au adresse on peut changer les valeurs d'une variable


    Valeur();
    std::cout << "&a " << &a << " a " << a << std::endl; //Une valeur peut être sur différente adresse
    ptrA = nullptr;
    std::cout << "ptrA " << ptrA << " &ptrA " << &ptrA << std::endl;
    ptrA++;
    std::cout << "ptrA " << ptrA << " &ptrA " << &ptrA << std::endl; //Prend de la valeur

                     ptrA = &a;
    ptrB = &b;
    std::cout << "&ptrA " << ptrA << " *ptrA  " << *ptrA << std::endl;
    std::cout << "&ptrB " << ptrB << " *ptrB  " << *ptrB << std::endl;
    std::cout << "&ptrA " << &ptrA << std::endl; //Garde l'adresse de a  mais change sa valeur
    std::cout << "Donc a ? " << a << std::endl;
    std::cout << "l'adresse de a ? " << &a << std::endl; // Donc une adresse peut avoir plusieur valeur
    std::cout << std::endl;
}
void RefExample(int &_value) //modifie le contenu de la variable
{
    _value *= 2;
}
void Adress(int _a)
{
    int* _ptrA = &_a;
    _ptrA++;
    cout << *_ptrA <<endl;
    cout << _ptrA <<endl;
    //delete _ptrA;
}
int CorectionAdress(int _i)
{
    int* _ptr = new int(_i);
    cout << _ptr << endl;
    int _tmp = *_ptr *= 2;
    delete _ptr;
    return _tmp;
}
int* AdressOf(int _i)
{
    return &_i;
}



*/
#pragma region array
/*
using namespace std;

int* intArray = nullptr;
int sizeArray = 0;

void InitArray(int _size)
{
    cout << "Set array size " << endl;
     _size = 0;
    cin >> _size;
    _size = _size <= 0 ? 1 : _size;
    intArray = new int[_size];
    cout <<"New int* array size :" << _size << endl;
}
void InsertValue()
{
    for (size_t i = 0; i < sizeArray; i++)
    {
        int _input;
        cin >> _input;
        cout << "New value " << _input << " at index : " << i << endl;
        intArray[i] = _input;
    }
}
void ReadArray()
{
    for (size_t i = 0; i < sizeArray; i++)
    {
        cout << intArray[i] << endl;
    }
    cout << "\o" << endl;
}
void Clear()
{
    delete[] intArray;
}
void Sort()
{
    int _tmp = 0;
    for(size_t i = 0; i < sizeArray; i++)
    {
        for (size_t j = i; j < sizeArray; j++)
        {
            if (intArray[i] > intArray[j])
            {
                _tmp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = _tmp;
            }
        }
    }
    
}


int main()
{
    while (true)
    {
        InitArray(sizeArray);
        InsertValue();
        ReadArray();
        Sort();
        ReadArray();
        Clear();
    }
}*/
#pragma endregion