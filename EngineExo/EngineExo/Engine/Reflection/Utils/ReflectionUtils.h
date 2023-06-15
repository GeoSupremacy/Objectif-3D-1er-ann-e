#pragma once
#include "../../Object/Object.h"
#include <istream>
#include <ostream>

namespace Engine::Reflection
{
	class ReflectionUtils
	{
		//Renvoie les noms de champs lié aux objects, si ces champs existent
	public:
		static void SerializePrimaryType(std::ostream& _os, const Object* _obj, const PrimaryType::String& _fieldName);
		static PrimaryType::String GetLine(std::istream& _is, const PrimaryType::String& _fieldName);
	};
}