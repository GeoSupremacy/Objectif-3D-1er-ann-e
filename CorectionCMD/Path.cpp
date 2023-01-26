#include "Path.h"
#include "StringUtils.h" /*../../Utils/String/StringUtils.h*/
std::string Path::GetPath(const std::string& _path)
{
    return StringUtils::Replace(_path, '\\', DirectorySeparator);
}

std::string Path::Combine(const std::initializer_list<std::string>& _path)
{
    const size_t _size = _path.size();
    size_t _index = 0;
    std::string _result = "";
    for (const std::string& _str : _path)
    {
        _result += _str;
        if (_index < _size - 1)
            _result += DirectorySeparator;
        _index++;
    }
    return _result;
}

std::string Path::GetParentDirectory(const std::string& _path)
{
    std::string _result = GetPath(_path);
    return _result.substr(0, _result.find_last_of(DirectorySeparator));
}

bool Path::HasExtension(const std::string& _path)
{
    return _path.find('.') != std::string::npos;
}
