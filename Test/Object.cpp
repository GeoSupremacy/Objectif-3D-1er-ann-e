#include "Object.h"
#include "FString.h"
#include "Boolean.h"
#include "FieldInfo.h"
#include <ranges>

#pragma region methods
int Core::Object::RegisterField(const char* _name, Object* _obj, int _mask)
{
	if (fields.contains(_name)) return fields.size();
	fields.insert(std::pair(_name, new FieldInfo(_name, _obj, _mask)));
	return fields.size();
}
Core::PrimitiveType::Boolean Core::Object::Equals(const Object* _obj) const
{
	return this == _obj;
}

Core::PrimitiveType::FString Core::Object::ToString() const
{
	return "";
}
std::vector<Core::FieldInfo*> Core::Object::GetFields() const
{
	std::vector<FieldInfo*> _result = std::vector<FieldInfo*>();
	for (std::pair<const char*, FieldInfo*> _field : fields)
		_result.push_back(_field.second);
	return _result;
}
std::vector<Core::FieldInfo*> Core::Object::GetFields(BindingFlags _flags) const
{
	std::vector<FieldInfo*> _result = std::vector<FieldInfo*>();
	for (std::pair<const char*, FieldInfo*> _field : fields)
	{
		if (_field.second->Flags() & _flags)
			_result.push_back(_field.second);
	}
	return _result;
}
Core::FieldInfo* Core::Object::GetField(const char* _name)
{
	if (!fields.contains(_name)) return nullptr;
	return fields[_name];
}
#pragma endregion methods
#pragma region operator

Core::Object& Core::Object::operator=(const Object* obj)
{
	return *this;
}
#pragma endregion operator