#pragma once
#include "Object.h"
namespace Core
{
	namespace PrimitiveType
	{
		class Boolean sealed : public Object
		{
#pragma region f/p
		private:
			bool value = false;
#pragma endregion f/p
#pragma region constructor
		public:
			O3DLIBRARY_API Boolean() = default;
			O3DLIBRARY_API Boolean(const bool _value);
			O3DLIBRARY_API Boolean(const Boolean& _copy);
#pragma endregion constructor
#pragma region override
		public:
			O3DLIBRARY_API FString ToString() const override;
#pragma endregion override
#pragma region operator
			O3DLIBRARY_API Boolean operator==(const Boolean& _other) const;
			O3DLIBRARY_API Boolean operator!=(const Boolean& _other) const;
			O3DLIBRARY_API operator bool() const;
			O3DLIBRARY_API Boolean operator !() const;
#pragma endregion operator
		};
	}
}