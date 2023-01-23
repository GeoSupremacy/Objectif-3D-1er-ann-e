#include "Language.h"

Language::Language(int _size, std::string* _table)
{
    
}

void Language::InsertLanguage(std::string _fr, std::string _engl)
{
    std::string* _tmp1 = table;
    std::string* _tmp2 = table[0][0];
    
    sizeColumn++;
    sizeline++;
    table = new int[sizeColumn][sizeline];
    for (size_t i = 0; i < sizeColumn - 1; i++)
    {
        for (size_t j = 0; j < sizeline - 1; j++)
        {
            table[i] = _tmp1[i];
            table[sizeColumn - 1] = _fr;
            table[i][j] = _tmp2[i][j];
            table[sizeColumn - 1][sizeline-1] = _engl;
        }
    }
}
