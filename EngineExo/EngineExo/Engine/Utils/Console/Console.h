#pragma once
#include "../../Object/Object.h"
#include "../../Utils/Interface/Log/ILogger.h"
#include <windows.h>

#define color_white 15
#define color_yellow 14
#define color_red 4

namespace Engine::Utils
{
	//Pr�venir les erreurs
	class Console : public Object
	{
		DECLARE_CLASS_INFO(Console, Object)
#pragma region f/p
	private:
		static const inline HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#pragma endregion
#pragma region constructor
	public:
		Console() = default;
	public:
		static void Log(const std::string& _msg);
		static void Log(const Object& _obj);
		static void Log(const ILogger* _obj);

		static void LogWarning(const std::string& _msg);
		static void LogWarning(const Object& _obj);
		static void LogWarning(const ILogger* _obj);

		static void LogError(const std::string& _msg);
		static void LogError(const Object& _obj);
		static void LogError(const ILogger* _obj);
#pragma endregion

	};
}

