#pragma once
#include "Object.h"

namespace Core
{
	
	namespace PrimitiveType
	{
		class FString;
	}
	class O3DLIBRARY_API ClipBoard :public Object
	{
#pragma region f/p
	private:

#pragma endregion f/p
#pragma region constructor/destructor
	public:
		ClipBoard() = default;
#pragma endregion constructor/destructor
#pragma region methods
	public:
		void Copy(const PrimitiveType::FString& _text);
#pragma endregion methods
#pragma region override
	public:

#pragma endregion override
#pragma region operator
	public:

#pragma endregion operator
	};
}

