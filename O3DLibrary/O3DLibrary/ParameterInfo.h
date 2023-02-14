#include "O3DLibrary.h"


struct O3DLIBRARY_API ParameterInfo
{
#pragma region f/p
private:
	const char* name = "";
	const char* typeName = "";
	int position = 0;
#pragma endregion f/p
#pragma region constructor
public:
	ParameterInfo() = default;
	ParameterInfo(const char* _name,const char* _typeName, int _position)
	{
		name = _name;
		typeName = _typeName;
		position = _position;

	}
#pragma endregion constructor
#pragma region methods
public:
	const char* Name() const
	{
		return name;
	}
	const char* TypeName() const
	{
		return typeName;
	}
	int Position() const
	{
		return position;
	}

};
#pragma endregion methods
