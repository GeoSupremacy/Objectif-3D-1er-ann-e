#pragma once
#include "../ValueType/ValueType.h"
#include <stdint.h>

namespace Engine::PrimaryType
{
class FGuid : public ValueType
{
	DECLARE_CLASS_INFO(FGuid, ValueType)
#pragma region f/p
private:
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
#pragma endregion f/p
#pragma region constructor
public:
	FGuid() = default;
	FGuid(int _a, int _b, int _c, int _d);
#pragma endregion constructor
#pragma region methods
public:
	static FGuid NewGuid();
#pragma endregion methods
#pragma region override
public:
	String ToString() const override;
	void SerializeField(std::ostream& _os, const String& _fieldName, int _index) override;
	void DeSerializeField(std::istream& _os, const String& _fieldName) override;
#pragma endregion override

};
 }

