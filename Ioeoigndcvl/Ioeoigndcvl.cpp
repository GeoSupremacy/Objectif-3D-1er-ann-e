// Ioeoigndcvl.cpp : This file contains the 'main' function. Program execution begins and ends there.
// I oeoig ! ndcvl
//I oeoig ! ndcvl

#include <algorithm>
#include <iostream>
#include <vector>
std::string Decrypt(const std::string& _crypted)
{
    std::string _newWord = _crypted;
    std::vector<char> _values = std::vector<char>();
    int _index = 0;
    while (_newWord.size() > 0)
    {
        if (_index % 2 == 0)
        {
            _values.push_back(_newWord[0]);
            _newWord = _newWord.erase(0,1);
        }
        else
        {
            _values.push_back(_newWord[_newWord.length() - 1]);
            _newWord = _newWord.erase(_newWord.length() -1, 1);
        }
        _index++;
    }
    return std::string(_values.begin(), _values.end());;
}
void Return(std::string _word)
{
    std::string _tranlate = "";
    char _a;
    for (int i =1; i< _word.size(); i++)
    {
        for (int j = 1; j < _word.size() - 1; j++)
        {
            _a = _word[i];
            _word[i] = _word[j];
            _word[j] = _a;
            break;
        }
    }
    std::cout<< _word <<std::endl;
}
int main()
{
    bool a = true;
    std::string newWord = "Ioeoig !ndcvl";
   

    std::cout<< a<<std::endl;
}

// Ioeoig !ndcvl -- "I love coding!"

