#pragma once
#include "Object.h"
#include "Map.h"
#include "Hash.h"
namespace Core
{
	namespace Collection
	{
		template<typename TKey, typename TValue>
		class O3DLIBRARY_API KeyValuePair : public Object
		{
			static_assert(std::is_base_of_v<Object, TKey>, "Pb key");
			static_assert(std::is_base_of_v<Object, TValue >, "Pb value");
#pragma region f/p
		private:
			TKey key = TKey();
			TValue value = TValue();
#pragma endregion f/p
#pragma region constructor/destructor
		public:
			KeyValuePair() = default;
			KeyValuePair(const TKey& _key, const TValue& _value)
			{
				key = _key;
				value = _value;
			}
			KeyValuePair(const KeyValuePair& _copy)
			{
				key = _copy.key;
				value = _copy.value;
			}
#pragma endregion constructor/destructor
#pragma region override
		public:
			PrimitiveType::FString ToString() const override
			{
				const FString& _keyStr = GetObjectToString(key);
				const FString& _valueStr = GetObjectToString(value);
				return PrimitiveType::FString::Format("Key: (), Values: () ", _keyStr, _valueStr);
			}
			int GetHashCode() const override
			{
				return key.GetHachCode(key) ^ value.GetHachCode(value) << 1;
			}	
#pragma endregion override
#pragma region override
		public:
			KeyValuePair operator= (const KeyValuePair& _other)
			{
				key = _other.key;
				value = _other.value;
				return *this;
			}
			bool operator ==(const KeyValuePair& _other)
			{
				return key ==_other.key&& value == other.value;
			}
			bool operator ==(const KeyValuePair& _other)
			{
				return !(*this == _other);
			}
			bool operator ==(const TKey& _other)
			{
				return key == _other;
			}
			bool operator !=(const KeyValuePair& _other)
			{
				return !(*this == _other);
			}
#pragma endregion override
		};
}
}
