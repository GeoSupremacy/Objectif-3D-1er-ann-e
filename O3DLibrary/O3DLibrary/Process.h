#pragma once
#include "Object.h"

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
	}
	namespace Diagnostics
	{
		class O3DLIBRARY_API Process : public Object
		{
#pragma region methods
		public:
			static void Start(const PrimitiveType::FString& _path, const PrimitiveType::FString& _parameters);
#pragma endregion methods
		};
	}
}
