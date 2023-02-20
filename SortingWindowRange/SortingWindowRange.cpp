// SortingWindowRange.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Cr�e une fonction qui retourne que les chiffres d�j� trier ordre croissant
//Si d�j� trier retourner (0,0)
// Comment savoir ce qui est d�j� trier?
// crer une liste
// Prendre les �l�ments de la liste d'entr� et de trier 
// Comparer les valeurs 
    // for for
        // prendre par paire de valeur et comparer celle-ci && V�rifier que la pair ne sorte pas du tableau
        //  
//          si oui on retourne les valeurs sinon on continue

#include <iostream>
#include <vector>
#include <algorithm>

void List(std::vector<int> _listInput)
{
    for (auto x : _listInput)
        std::cout << x;
    std::cout << std::endl;
}
std::vector<int> Min_window_to_sort(std::vector<int> _listInput)
{
    bool isSorted = false;
    std::vector<int> _listOuput = std::vector<int>();

    if (std::is_sorted(_listInput.begin(), _listInput.end()))
    {
        _listOuput.push_back(0);
        _listOuput.push_back(0);
        return _listOuput;
    }
    
    std::vector<int> enter = std::vector<int>();

    for (size_t i = 0; i < _listInput.size()-1; i++)
    {
        
        enter.push_back(_listInput[i++]);
        enter.push_back(_listInput[i]);
        i -= 1;
        
        if (std::is_sorted(enter.begin(), enter.end()) && true ==isSorted)
            return _listOuput = enter;
        if (std::is_sorted(enter.begin(), enter.end()))
          _listOuput = enter;
        else
        {
          isSorted = true;
        }
        enter.clear();
       
    }
    return _listOuput;
}


int main()
{
    std::vector<int> min_window_to_sort = { 4, 1, 7, 5, 6, 8, 9 };
    std::vector<int> _listOuput = Min_window_to_sort(min_window_to_sort);
    for (auto x : _listOuput)
        std::cout << x;
}
