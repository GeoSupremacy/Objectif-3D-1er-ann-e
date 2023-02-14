#pragma once
#include "O3DLibrary.h"
#include "MethodInfo.h"
#include <iostream>
#include <map>
#include <vector>


#pragma warning(disable: 4251)
#pragma warning(disable: 4244)
#pragma warning(disable: 4275)

namespace Core
{
	
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
	}
	enum class BindingFlags;
	class FieldInfo;


#define REGISTER_FIELD(name, var, mask) const int Field##name = RegisterField(#name, var, mask);
#define REGISTER_METHOD(name, function, instance, parameters) const int Function_##name = RegisterFunction(name, function, instance, parameters);

	
	class O3DLIBRARY_API  Object
	{
#pragma region f/p
	private:
		std::map<const char*, FieldInfo*> fields = std::map<const char*, FieldInfo*>();
		std::map<const char*, BaseMethodInfo*> methods = std::map<const char*, BaseMethodInfo*>();
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		Object() = default;
		virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
	protected:
		int RegisterField(const char* _name, Object* _obj, int _mask);
		template<typename Result, typename Class, typename... Params>
		int RegisterFunction(const char* _name, Result(Class::* ptr)(Params...), Class* _instance, std::vector < ParameterInfo > _params = {});
	public:
		 virtual Core::PrimitiveType::Boolean Equals(const Object* _obj) const;
		 virtual Core::PrimitiveType::FString ToString() const;
		 virtual int GetHashCode() const;
		 std::vector<FieldInfo*> GetFields() const;
		 std::vector<FieldInfo*> GetFields(BindingFlags _flags) const;
		 FieldInfo* GetField(const char* _name) ;
		 template<typename T>
		 void SetValue(Object* obj);
		 template<typename T>
		 void SetFieldValue(const char* _name, T* _value);

		 template<typename Result, typename... Params>
		 Result Invoke(const char* _name, Params... _params);
		
		 template<typename Result, typename... Params>
		 MethodInfo<Result, Params...>* GetMethod(const char* _name);
#pragma endregion methods
#pragma region operator
		 virtual Object& operator=(const Object* obj);
#pragma endregion operator
	};
	typedef Object* object;
#pragma region template
	template<typename Result, typename Class, typename ...Params>
	inline int Object::RegisterFunction(const char* _name, Result(Class::* ptr)(Params...), Class* _instance, std::vector <ParameterInfo> _params)
	{
		if (methods.contains(_name)) return methods.size();
		MethodInfo<Result, Params...>* _method = new MethodInfo<Result, Params...>(_instance, ptr, _params);
		methods.insert(std::pair(_name, _method));
		return methods.size();
	}
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
	 template<typename Result, typename ...Params>
	 inline Result Object::Invoke(const char* _name, Params ..._params)
	 {
		 MethodInfo<Result, Params...>* _method = GetMethod<Result, Params...>(_name);
		 if (_method == nullptr) return Result();
		 return _method->Invoke(_params...);
	 }
	 template<typename Result, typename ...Params>
	 inline MethodInfo<Result, Params...>* Object::GetMethod(const char* _name)
	 {
		 if (!methods.contains(_name)) return nullptr;
		 return dynamic_cast<MethodInfo<Result, Params...>*>(methods[_name]);
	 }
#pragma endregion template 
	
	 
}