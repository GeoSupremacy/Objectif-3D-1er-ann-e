#include "InspectorWindow.h"
#include "../../Window/Engine/EngineWindow.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../Selection/Selection.h"

#pragma region constructor
Engine::Editor::InspectorWindow::InspectorWindow() : super("Inspector")
{
	const int _width = Window::EngineWindow::Instance()->Width();
	const int _height = Window::EngineWindow::Instance()->Height();
	shape = new sf::RectangleShape(PrimaryType::Vector2(300, _height));
	shape->setFillColor(sf::Color(50, 50, 50, 255));
	const PrimaryType::Vector2 &_position = PrimaryType::Vector2(_width - 300, 25);
	SetPosition(PrimaryType::Vector2(_position));
	editor = new Editor(nullptr);
	editor->SetPosition(&_position + PrimaryType::Vector2(15, 0));
	Selection::OnSelectionChanged.AddDynamic(this, &InspectorWindow::OnSelectedChanged);
}
Engine::Editor::InspectorWindow::~InspectorWindow()
{
	Selection::OnSelectionChanged.RemoveDynamic(this, &InspectorWindow::OnSelectedChanged);
	delete editor;
	editor = nullptr;
}
Engine::Editor::InspectorWindow::InspectorWindow(const InspectorWindow& _copy) = default;
#pragma endregion constructor
#pragma region methods
void Engine::Editor::InspectorWindow::OnSelectedChanged(Object* _o)
{
	if (editor->ObjectEdit() != nullptr)
	{
		//TODO if object to edit is not nullptr serialize this
		//TODO GetAssetPath
	}
	editor->SetObjectEdit(_o);
	editor->InspectorGUI();

}
#pragma endregion methods