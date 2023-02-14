#pragma once
#include "Object.h"
#include "FString.h"
#include <windows.h>


namespace Core
{
	namespace Net
	{
		class O3DLIBRARY_API Url : public Object
		{
#pragma region f/p
		private:
			PrimitiveType::FString path = "";
#pragma endregion f/p
#pragma region constructor/destructor
		public:
			Url() = default;
			Url(PrimitiveType::FString& _path);
			Url(const Url & _copy);
#pragma endregion constructor/destructor
#pragma region override
		public:
			PrimitiveType::FString ToString() const;
			PrimitiveType::FString Path() const;
			int GetHashCode() const override;

#pragma endregion override
#pragma region operator
		public:
			operator LPCWSTR() const;
#pragma endregion operator
		};
	}
}


