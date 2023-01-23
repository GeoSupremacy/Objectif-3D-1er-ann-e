// GameOfDeadString28_10_2002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>



int main()
{
    
    // 1234 = 2344 ;
    std::string a = "1234";
    std::cout << a<<std::endl;
    for (int i = a.length(); i>0; i--)
    {
        int j = i - 1;
        char _a = a[i];
        
            char b = a[j];
            if (_a > b)
            {
                a[j] = _a;
                if (a[j] = '0')
                {

                }
            }
            
        
    }
    std::cout <<a;
}


#pragma region rest
/*
void Reverse(int _number)
{

    std::string  _Number = std::to_string(_number);
    int _result;

    for (int i = 0; i < _Number.size(); i++)
    {
        char _a = _Number[i];

        for (int j = 1; j < _Number.size(); j++)
        {
            char _b = _Number[j];
            _Number[i] = _b;
            _Number[j] = _a;
        }

    }
    _result = _number- stoi(_Number);
    std::cout << _number <<"-"<< _Number<<"= "<< _result;

}

int main()
{
    Reverse(2);


}
-----------------------
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::string entree = "123456789";
    int _result =0;
    for (int i = 0; i < entree.size(); i++)
    {
        char T = entree[i];
        for (int i = 0; i < entree.size(); i++)
        {
            if ((int)T > (int)entree[i])
            {

                _result = (int)T;
            }


        }
    }

    std::cout << "Result more big: " << _result;

    return 0;
}
----------------------------
std::string Replace(const std::string& _str, const std::string& _str1, const std::string& _str2)
{}
int MaxNum(const std::string& _str)
{
    const std::string _number = Replace(_str, "", "");
    int* _tab = new int[_str.size()];

    for (int i = 0; i < _number.size(); i++)
    {
        _tab[_number[i]] - '0']++;
    }

    int _result = 0, mulltiplier = 1;

    for (int i = 0; i < _number.size(); i++)
    {
        _result += (i * mulltiplier);
        _tab[i]--;
        mulltiplier *= 10;
    }
    return _result;
}
*/
#pragma endregion rest