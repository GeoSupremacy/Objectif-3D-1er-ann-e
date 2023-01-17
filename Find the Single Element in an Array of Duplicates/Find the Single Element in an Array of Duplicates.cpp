#include <iostream>
#include <vector>
#include <algorithm>


#pragma region corr
void Result()
{
    int i, j, size;
    std::vector<int> _tab = { 1, 1, 3, 4, 4, 5, 5, 6 };
   sort(_tab.begin(), _tab.end());
   std::cout<<"\n\nDuplicate Values in Given Array are :: \n\n";
    for (i = 0; i < _tab.size()-1; i++)
    {
        for (j = i + 1; j < _tab.size(); j++)
        {
            if (_tab[j] != _tab[i])
            {
                std::cout << " " << _tab[i] << " ";
            }
        }
    }


}
#pragma endregion corr
int main()
{
    std::vector<int> _tab = { 1, 1, 3, 4, 4, 5, 5, 6 };
    sort(_tab.begin(), _tab.end());
    bool isUnique = false;
    bool isMax = false;
    for (size_t i = 0; i < _tab.size(); i++)
    {
        int short _a = _tab[i];
        int short _b = 0;
        if (!isMax)
        {
            if (i != _tab.size() - 2)
            {
                
                if (isUnique)
                {
                    if (_a != _tab[i + 1])
                        std::cout << _a << std::endl;
                    isUnique = false;

                }
                else if (_a != _tab[i + 1])
                    isUnique = true;
            }
            else
            {
                isMax = true;
                if (_a != _tab[i + 1])
                    std::cout << _tab[i + 1] << std::endl;
            }
        }
    }

    std::cout << std::endl;

    Result();
    return 0;
   
}

/*Trouver un nombre unique dans un tableau duppliqué
Le trouver en un tour

Trier
A chaque élément du tableau compare le suivant
si il est bon on continu
sinon au revoir
par 2
*/