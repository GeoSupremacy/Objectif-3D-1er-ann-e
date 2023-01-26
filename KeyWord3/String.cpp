#include "String.h"
#include <cctype>
String::String(const char* _value)
{
    if (_value == nullptr) _value = "";
    const int _otherLength = strlen(_value);
    const int _newLength = mLength + _otherLength;
    char* _char = new char[_newLength + 1];
    // ReSharper disable CppDeprecatedEntity
    strcpy(_char, value);
    // ReSharper disable once CppDeprecatedEntity
    strcat(_char, _value);//
    value = _char;
    mLength = _newLength;
}

String::String(const String& _copy)
{
    if (_copy.value == nullptr) return;
    const int _length = _copy.mLength;
    char* _char = new char[_length + 1];
    memcpy(_char, _copy.value, _length+1);
    value = _char;
    mLength = _length;
}

String::~String()
{
    delete value;
}

String String::ToLower() const
{
    char* _result = new char[mLength];
    for (int i = 0; i < mLength; i++)
        _result[i] = std::tolower(value[i]);
    _result[mLength] = '\0';
    return _result;
}

String String::ToUpper() const
{
    char* _result = new char[mLength];
    for (int i = 0; i < mLength; i++)
        _result[i] = std::toupper(value[i]);
    _result[mLength] = '\0';
    return _result;
}

bool String::Contains(const String& _str) const
{
    for (int i = 0; i < mLength; i++)
    {
        if (value[i] == _str.value[0])
        {
            bool _isValid = true;
            for (int x = i; x < i + _str.mLength && _isValid; x++)
            {
                if (value[x] != _str.value[x - i])
                    _isValid = false;
            }
            if (_isValid) return true;

        }
    }
    return false;

}

std::vector<String> String::Split(const char _c)
{
    std::vector<String> _result =  std::vector<String>();
    int _start = 0;
    for (int i = 0; i < mLength; i++)
    {
        if (value[i] == _c)
        {
            String _toAdd = "";
            for (int x = _start; x < i; x++)
            {
                _toAdd += value[x];
                _result.push_back(_toAdd);
                _start = i + 1;
            }
        }
    }

    String _toAdd = "";
    for (int x = _start; x < mLength; x++)
        _toAdd += value[x];
    _result.push_back(_toAdd);
    return _result;
}

String String::Replace(const char _old, const char _new)
{
    char* _char = new char[mLength];
    for (int i = 0; i < mLength; i++)
    {
        _char[i] = value[i] == _old ? _new : value[i];
    }
    _char[mLength] = '\0';
    return _char;
}
int String::LastIndexof(const char _c)
{
    int _result = -1;
    for (int i = 0; i < mLength; i++)
    {
        if (value[i] == _c)
            _result = i;

    }
    return _result;
}
int String::FirstIndexof(const char _c)
{
    int _result = -1;
    for (int i = 0; i < mLength; i++)
    {
        if (value[i] == _c)
            _result = i;

    }
    return -1;
}
String String::Join(const std::vector<String>& _values)
{
    String _result = *this;
    const size_t _size = _values.size();
    for (int i = 0; i < _size; i++)
    {
        _result += _values[i];
    }
    return _result;
}
String String::Trim()
{
    const int _newLength = mLength - Countof(' ');
    char* _tab = new char[_newLength];
    int _index = 0;
    for (int i = 0; i < mLength; i++)
    {
        if (value[i] == ' ') continue;
        _tab[_index++] = value[i];
    }
    _tab[_newLength] = '\0';
    return _tab;
}
String String::SubString(const int _begin, const int _end) const
{
    String _result = "";
    for (int i = _begin; i < _end; i++)
    {
        _result += value[i];

    }
    return _result;
}
String String::SubString(const int _begin) const
{
    return SubString(_begin, mLength);
}
int String::Countof(const char _c)
{
    int _result = 0;
    for (int i = 0; i < mLength; i++)
    {
        if (value[i] == _c)
            _result++;

    }
    return -_result;
}
bool String::IsNullOrEmpty(const String& _str)
{
    return _str.value == nullptr || _str.mLength == 0;
}
#pragma region operator
String& String::operator+=(const char _c)
{
    const int _newLenght = mLength + 2;
    char* _char = new char[_newLenght];
    strcpy(_char, value);
    _char[mLength] = _c;
    _char[mLength + 1] = '\0';
    value = _char;
    mLength += 1;
    return *this;
}
String& String::operator+=(const String& _str)
{
    const int _newLenght = mLength + _str.mLength;
    char* _char = new char[_newLenght + 1];
    strcpy(_char, value);
    strcat(_char, _str.value);
    value = _char;
    mLength = _newLenght;
    return *this;
}
String String::operator+(const String& _c)
{
    const int _newLenght = mLength + _c.mLength;
    char* _char = new char[_newLenght + 1];

    strcpy(_char, value);
    strcat(_char, _c.value);
    return _char;
}
String::operator const char* ()
{
    
        return value;
    
}
#pragma endregion operator