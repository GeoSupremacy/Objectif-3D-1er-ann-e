#pragma once
#include "../Object/Object.h"
#include "../UI/Element/UIElement.h"
#include "../PrimaryType/Vector2/Vector2.h"

namespace Engine::Editor
{
	enum class EValueType
	{
		Int,
		Bool,
		Float,
		Double,
		String,
		List,
		Vector,
		Object
	};
	class Editor :public Object
	{
		DECLARE_CLASS_INFO(Editor, Object)
	private:
		std::vector<UI::UIElement*> elements = std::vector<UI::UIElement*>();
		Object* currentObjectEdit = nullptr;
		PrimaryType::Vector2 currentPosition = PrimaryType::Vector2(0, 0);
		PrimaryType::Vector2 initialPosition = PrimaryType::Vector2(0, 0);
	public:
		Editor() = default;
		Editor(Object* _object);
	private:
		void CreteToggleProperty(Engine::Reflection::FieldInfo* _field);
	public:
		void SetObjectEdit(Object* _object);
		void SetPosition(PrimaryType::Vector2* _position);
		virtual void InspectorGUI();
		Object* ObjectEdit();
		std::vector<UI::UIElement> Elements() const;
		EValueType GetValueType(Object* _object);
		void DisplayProperties(const Reflection::FieldInfo* _filedInfo);
	};
}

