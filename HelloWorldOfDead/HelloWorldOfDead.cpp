#include "Array.h"
#include <iostream>
#include <vector>
#include <format>
#pragma region comment
/*
* Afficher hello world 
*/
#pragma endregion comment


std::vector<std::string> Split(const std::string& _str, const std::string& _delimiter)
{
    std::string _string = _str;
    size_t _posStart = 0, _posEnd = 0, _delimLenght = _delimiter.length();
    std::vector<std::string> _result = std::vector<std::string>();

    while ((_posEnd = _string.find(_delimiter, _posStart)) != std::string::npos)
    {
        _result.push_back(_string.substr(_posStart, _posEnd - _posStart));
        _posStart = _posEnd + _delimLenght;
    }
    _result.push_back();
    while ((_posEnd = _string.find(_delimiter, _posStart)) != std::string::npos)
    {
        _result.erase(
            0_index);
    }

    return _result;
}

std::string Banner(const std::string& _a, const std::string& _b)
{
    std::string  _result = "";
    for (int i = 0; i < _a.size(); i++)
        _result += std::format("{} {`\n", _a[i], _b[_b.size() - i - 1]);
    return _result;
}
int main()
{
    std::string _str = "Hello World";
    std::vector<std::string> _splited = Split(_str, "");
    if (_splited[0].size() != _splited[1].size()) return -3;
    std::string _result = Banner(_splited[0], _splited[1]) + "\n";
    _result += Banner(_splited[1], _splited[0]);
    std::cout << _result << std::endl;
    return 0;
    Array _array;
    _array.Size("Hello World!");
    
    std::string _str = "Hello World!";
}

