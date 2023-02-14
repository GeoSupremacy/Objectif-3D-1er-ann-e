#pragma once
#include "Object.h"
#include "Exception.h"
#include "Url.h"

namespace Core
{
	namespace Event
	{
		template<typename Res, typename... Params>
		class Delegate: public  Object
		{	
#pragma region f/p
		private:
			typedef Res(Object::* Function)(Params...);
			Function functionPtr = nullptr;
			Object* instance = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
		public:
			Delegate(nullptr_t)
			{
				functionPtr = nullptr;
				instance = nullptr;
			}
#pragma endregion constructor/destructor
#pragma region methods
		public:
			template<typename Class,typename Res, typename... Params>
			void SetDynamique(Class* _instance, Res(Class::* ptr)(Params...))
			{
				if (!std::is_base_of_v<Object, Class>)
					throw Exception("Class must be inherited of Object");
				functionPtr = reinterpret_cast<Function>(ptr);
				instance = _instance;
			}
			template<typename Class, typename Res, typename... Params>
			void SetDynamique(nullptr_t, Res(Class::* ptr)(Params...))
			{
				if (!std::is_base_of<Object, Class>)
					throw Exception("Class must be inherited of Object");
				functionPtr = nullptr;
				
			}
			Res Invoke(Params... _params)
			{
				if (instance == nullptr)
				throw Exception("instance is nullptr !");
				if (functionPtr == nullptr)
					throw Exception("instance is nullptr !");
				return (instance->*functionPtr) (_params...);
			}
			void* GetAddresss() const
			{
				return (void*&)functionPtr;
			}
#pragma endregion methods
#pragma region operator
		public:
			void operator=(nullptr_t)
			{
				instance = functionPtr = nullptr;
			}
			bool operator==(const Delegate& _other)
			{
				return GetAddresss() == _other.GetAddresss();
			}
			bool operator!=(const Delegate& _other)
			{
				return !this->operator==(_other);
			}


			template<typename Class>
			bool operator ==(Class* _instance)
			{
				return instance == _instance;
			}
			template<typename Class>
			bool operator !=(Res(Class::* ptr) (Params...))
			{
				return !this->operator==(ptr);
			}
#pragma endregion operator
		};
	}
}