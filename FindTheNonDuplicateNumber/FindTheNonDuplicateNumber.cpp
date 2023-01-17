#include <iostream>
#include <algorithm>
#include <vector>


void SingleNumber(std::vector<int> _list) {

    
        std::cout << "Amongus !: ";
        sort(_list.begin(), _list.end());
        bool isSame = false;

        for (size_t i = 0; i < _list.size()-1; i++)
            if (!isSame)
                if (_list[i] == _list[i + 1])
                    isSame = true;
                else
                    std::cout << _list[i] << " ";
            else
                isSame = false;

        std::cout << std::endl;
    
}

int main()
{
    std::vector<int> _list = { 1,2,3,4,5,6,7,8,9,10,  1,2,3,5,8,9};
    SingleNumber(_list);
}

#pragma region Comment
/*
* 123456789
* Trouver si un nombre n'a une copie!
* 
* Trier la liste
* Prendre le 1er nombre
* Comparer si le premier nombre et pareil que le deuxième
* si oui parcourir le compter combien de fois
* Sinon print
*/
#pragma endregion Comment
#pragma region Orgueil
/*
* Le but était d'identifier s'il n'y avait pas de pair et non d'un nombre dupliquer
std::sort(_list.begin(), _list.end());
        bool IsNow = false;
        bool isSame = true;
        bool next = true;
        int _temp = 0;
        int max = 0;
        int same = _list[0];
        int copy;


        for (size_t i = 0; i < _list.size() - 1; i++)
        {
            if (isSame)
            {
                if (same == _list[i + 1])
                    copy++;
                else
                {
                    same = _list[i + 1];
                    _temp = copy;
                    copy = 0;
                    isSame = false;
                }
            }
            else
            {
                if (same == _list[i + 1])
                    copy++;
                else
                {
                    if (_temp >= copy)
                    {
                        std::cout << same << "";
                        max = _temp;
                        IsNow = true;
                        isSame = true;
                    }
                    _temp = copy;
                    isSame = false;
                }
            }

        }*/
#pragma endregion Orgueil