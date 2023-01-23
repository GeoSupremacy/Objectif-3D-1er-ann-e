#pragma once
#include <iostream>
#include <map>
#include <vector>


#pragma warning(disable: 4251)

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
	}
	enum class BindingFlags;
	class FieldInfo;
	class Object
	{
#pragma region constructor/destructor
	public:
		std::map<const char*, FieldInfo*> fields = std::map<const char*, FieldInfo*>();
		Object() = default;
		virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
	protected:
		int RegisterField(const char* _name, Object* _obj, int _mask);
	public:
		virtual Core::PrimitiveType::Boolean Equals(const Object* _obj) const;
		virtual Core::PrimitiveType::FString ToString() const;
		std::vector<FieldInfo*> GetFields() const;
		std::vector<FieldInfo*> GetFields(BindingFlags _flags) const;
		FieldInfo* GetField(const char* _name);
		template<typename T>
		void SetValue(Object* obj);
		template<typename T>
		void SetFieldValue(const char* _name, T* _value);
#pragma endregion methods
#pragma region operator
		virtual Object& operator=(const Object* obj);
#pragma endregion operator
	};
	typedef Object* object;

	template<typename T>
	void Object::SetValue(Object* obj)
	{
		*((T*)this) = obj;
	}

	template<typename T>
	inline void Object::SetFieldValue(const char* _name, T* _value)
	{
		if (!fields.contains(_name)) return;
		fields[_name] = _value;
	}



}
