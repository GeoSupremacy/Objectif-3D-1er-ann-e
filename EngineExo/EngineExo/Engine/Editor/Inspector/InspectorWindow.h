#pragma once
#include "../Window/EditorWindow.h"
#include "../Editor.h"
namespace Engine::Editor
{
	class InspectorWindow : public EditorWindow
	{
		DECLARE_CLASS_INFO(InspectorWindow, EditorWindow)
#pragma region f/p
	private:
		Editor* editor = nullptr;
#pragma endregion f/p
#pragma region constructor
	public:
		InspectorWindow();
		~InspectorWindow() override;
#pragma endregion constructor
#pragma region methods
	public:
		void OnSelectedChanged(Object* _o);
#pragma endregion methods
	};
}

