#include "UUID.h"
#include "../../Event/Action/Action.h"
#include "../String/String.h"


#pragma region constructor
Engine::PrimaryType::FGuid::FGuid(int _a, int _b, int _c, int _d) : super()
{
    a = _a;
    b = _b;
    c = _c;
    d = _d;


}
Engine::PrimaryType::FGuid::FGuid(const FGuid& _copy) : super(_copy)
{
    a = _copy.a;
    b = _copy.b;
    c = _copy.c;
    d = _copy.d;


}
#pragma endregion constructor
#pragma region methods
Engine::PrimaryType::FGuid Engine::PrimaryType::FGuid::NewGuid()
{
    FGuid _result(0, 0, 0, 0);
    CoCreateGuid((GUID*)&_result); //Créer un unique ID
    return _result;
}
#pragma endregion methods
#pragma region override
Engine::PrimaryType::String Engine::PrimaryType::FGuid::ToString() const
{
    char _str[37];
    snprintf(_str, sizeof(_str), "%08X-%08X-%08X-%08X", a, b, c, d);
    return _str;

}
void Engine::PrimaryType::FGuid::SerializeField(std::ostream& _os, const String& _fieldName, int _index)
{
    ValueType::SerializeField(_os, _fieldName, _index);
}
void Engine::PrimaryType::FGuid::DeSerializeField(std::istream& _os, const String& _fieldName)
{
    ValueType::DeSerializeField(_os, _fieldName);
}
#pragma endregion override