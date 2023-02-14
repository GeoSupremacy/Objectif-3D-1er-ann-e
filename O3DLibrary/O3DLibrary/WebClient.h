#pragma once
#include <Windows.h>
#include "Object.h"
#include "FString.h"
#include "Url.h"
#include "ActionInternal.h"


namespace Core
{
	namespace Net
	{
		class O3DLIBRARY_API WebClient : public Object
		{
#pragma region f/p
		private:
			Url url = Url();
		public:
			Action<float> OnDownloadProgress = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
		public:
			WebClient() = default;
			WebClient(const Url& _url);
			WebClient(const WebClient& _copy);
#pragma endregion constructor/destructor
#pragma region methods
		public:
			void DownloadFile(const PrimitiveType::FString& _pathFile);
#pragma endregion methods
		};
	}
}
