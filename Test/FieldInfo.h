#pragma once
#include "Object.h"
#include "FString.h"
#include "BindingFlags.h"


namespace Core
{

	namespace Boolean
	{
		class Boolean;
	};
	class FieldInfo : public Object
	{
#pragma region f/p
	private:
		PrimitiveType::FString name = "";
		object reflectedObject = nullptr;
		BindingFlags flags = BindingFlags::Private;
#pragma endregion f/p
#pragma region constructor
	public:
		FieldInfo() = default;
		FieldInfo(const PrimitiveType::FString& _name, object _reflectedObject, int _mask);
#pragma endregion f/p
#pragma region methods
	public:
		PrimitiveType::Boolean IsPublic() const;
		PrimitiveType::Boolean IsPrivate() const;
		PrimitiveType::Boolean IsStatic() const;
		PrimitiveType::Boolean IsConst() const;
		PrimitiveType::FString Name() const;
		BindingFlags Flags() const;
		object ReflectedObject() const;
#pragma endregion methods
#pragma region override
		PrimitiveType::FString ToString() const override;
		Object& operator=(const Object* obj) override;
#pragma region override
	};

}

