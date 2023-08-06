
#include <iostream>
#include <vector>
#include <map>

using namespace std;


map <int, vector<char>> phone
{
    { 0, {'a', 'b', 'c'}},
    { 1, {'d', 'e', 'f'}},
    { 2, {'g', 'h', 'i'}},
    { 3, {'j', 'k', 'l'}},
    { 4, {'m', 'n', 'o'}},
    { 5, {'p', 'q', 'r', 's'}},
    { 6, {'t', 'u', 'v'}},
    { 7, {'w', 'x', 'y', 'z'}},
};
vector<string> validWorld = {"dog", "frog"};


vector<string> MakeWorld(const string _numberPhone)
{
    vector<string> goodWord;
    //Vf each validWord
    for (size_t x = 0; x < validWorld.size(); x++)
    {
        string _word = validWorld[x];
        int index = 0;
        //Save word valid and return
        string _validWorld;

        for (size_t i = 0; i < _numberPhone.size(); i++)
        {
            int  id = _numberPhone.at(i) - '0';
            vector<char> currentChar = phone.at(id);

            for (size_t j = 0; j < _word.size(); j++)
            {
                for (size_t y = 0; y < currentChar.size(); y++)
                    if (_word[j] == currentChar[y])
                        index++;
              
                if (index == _word.size())
                {
                    index = 0;
                    goodWord.push_back(_word);
                }
            }
        }
    }
    return goodWord;
}
void DisplayWord(const vector<string> _word)
{
    for (size_t i = 0; i < _word.size(); i++)
        cout << _word[i] << endl;
}


int main()
{
    DisplayWord(MakeWorld("1425"));
    return 0;
}

