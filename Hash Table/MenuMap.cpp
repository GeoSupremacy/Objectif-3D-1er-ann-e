#include "MenuMap.h"


#pragma region f/p

#pragma endregion f/p
#pragma region constructor/destructor

#pragma endregion constructor/destructor
#pragma region methods
void MenuMap::DisplayAllMap() const
{
    if (map.size() <=0)
        std::cout << "It's empty" <<std::endl;
    else
    {
        for (auto el : map)
        {
            std::cout << "Key: " << el.first << std::endl;
            std::cout << "Value: " << el.second << std::endl;
            std::cout << std::endl;
        }
    }
    
    
}
void MenuMap::SwitchMenu(const std::string _word)
{
    if ("Display" == _word)
    {
        system("CLS");
        DisplayAllMap();
    }
    else if ("Insert" == _word)
    {
        system("CLS");
        Add();
    }
    else if ("Remove" == _word)
    {
        system("CLS");
        Remove();
    }
    else
        Home();
}
void MenuMap::Add()
{
    
    std::string _newElement;
    std::cout << "Add new element by name" << std::endl;
    std::cin >> _newElement;
    if ("return" == _newElement)
    {
        system("CLS");
        Home();
    }
    map.insert({ Hachage(_newElement), _newElement });
    system("CLS");
    std::cout << " New element create!" << std::endl;
    Add();
}
void MenuMap::Remove()
{
    std::string _DeleteElement;

    DisplayAllMap();
    std::cout << "Delete  element by name or use 'clear' for delete all" << std::endl;
    std::cin >> _DeleteElement;
    if ("return" == _DeleteElement)
    {
        system("CLS");
        Home();
    }
    else if (Check(_DeleteElement))
    {
        system("CLS");
        std::cout << "Mmmh Monke :)" << std::endl;
        Remove();
    }
    else if ("clear" == _DeleteElement)
            map.erase(map.begin(), map.end());

    map.erase(Hachage(_DeleteElement));
    system("CLS");
    std::cout << " The element " << _DeleteElement << " is delete!" << std::endl;
    Remove();
}
bool MenuMap::Check(std::string _checkElement)
{
    bool monke = false;

    for (auto el : map)
    {
        if (_checkElement == el.first)
            return true;
    }
    return monke;
    
}
bool MenuMap::Home()
{
  
    std::string _word;

    while (isNotExist)
    {
        std::cout << "Display           Insert           Remove" << std::endl;
        std::cout << "tap => exit for left" << std::endl;
        std::cin >> _word;
        system("CLS");
        if ("exit" == _word)
           return isNotExist = false;
        SwitchMenu(_word);
        
    }
    system("CLS");
}
#pragma endregion methods
#pragma region operator

#pragma endregion operator


