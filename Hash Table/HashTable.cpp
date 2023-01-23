#include "HashTable.h"
#include <time.h>
#include <random>
#include <windows.h>


#pragma region constructor/destructor
HashTable::HashTable()
{
    size = 14;

    for (size_t i = 0; i < 14; i++)
    {
        std::string _nameclass = nameClassProg1[i];
        map.insert({ Hachage(nameClassProg1[i]),_nameclass });
    }
}
#pragma endregion constructor/destructor
#pragma region methods
std::string HashTable::Hachage(std::string _hach)
{
    int i = 0;
    std::string _indice =" ";
    

    for (i = 0; i < alphabet.size(); i++)
    {
        for (size_t j = 0; j < _hach.size(); j++)
        {
            if (alphabet[i] == _hach[j])
            {

                _indice = _indice + convert[i];
            }
        }
       
    }
    return _indice;
}
int HashTable::Random(const int _range)
{
    int _id;
    srand(time(0));
    return _id = rand() % _range;
}
void HashTable::Init(const int _nbrElement, const int _sizeMap)
{
    size = _sizeMap;
    const int _csizeMap = _nbrElement;
    
    char _word;
    std::string name;
    int _sizeName;
    int randomWord;

    for (size_t i = 0; i < _csizeMap; i++)
    {
        Sleep(10);
        _sizeName = Random(size);
        
        for (int j = 0; j < _sizeName; j++)
        {
            Sleep(10);
            randomWord = Random(alphabet.size());
           
            _word = alphabet[randomWord];
            name += _word;
        }
       map.insert({ Hachage(name),name });
       name = "";

     }
}
void HashTable::Found(std::string _indice)
{
    bool isthat;
    for (auto el : map)
    {
        if (el.second != _indice)
            isthat = false;
        else
            map.at(Hachage(_indice));
        if (!isthat)
            std::cout << "Not found" << std::endl;
    }

    
}
void HashTable::Selected()
{
    std::string _word;
    Found(Hachage(_word));
}
void HashTable::Lack()
{
    std::vector<std::string> lack = nameClassProg1;

    for (size_t i = 0; i < nameClassProg1.size(); i++)
        for (auto el : map)
            if (el.second == lack[i])
                lack[i].erase();
    
    for (size_t i = 1; i < lack.size(); i++)
        if (""!= lack[i])
            std::cout << "lack:  " << lack[i] << std::endl;
  
}
#pragma endregion methods

