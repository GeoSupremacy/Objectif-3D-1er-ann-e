#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../UI/Button/Button.h"
#include "../../UI/Toggle/Toggle.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../Time/Time.h"
#include "../../Editor/Window/EditorWindow.h"


#pragma region constructor
Engine::Window::EngineWindow::EngineWindow() : super("Engine", 900, 700) { }

Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy): super(_copy.name, _copy.width, _copy.height) { }
#pragma endregion
void Engine::Window::EngineWindow::RegisterEditorWindow(Editor::EditorWindow* _window)
{
	editorWindows.push_back(_window);
}
void Engine::Window::EngineWindow::UnRegisterEditorWindow(Editor::EditorWindow* _window)
{
	std::erase(editorWindows,_window);
}
#pragma region override
void Engine::Window::EngineWindow::Test()
{
	LOG("Button Click!")
}
void Engine::Window::EngineWindow::Open()
{
	UI::Button* button = new UI::Button("Play", 100, 100);
	button->addListener(this, &EngineWindow::Test); 
	button->SetPosition(PrimaryType::Vector2(200, 200));

	UI::Toggle* toggle = new UI::Toggle(true);
	
	super::Open();
}
void Engine::Window::EngineWindow::OnUpdate()
{
	Time::deltaTime = clock.restart().asSeconds();
	Manager::GameObjectManager::Instance()->Update();
	Clear();
	Manager::GameObjectManager::Instance()->Draw(this);
	Manager::EventSystem::Instance()->Draw(renderer);
	for (Editor::EditorWindow* _editorWindow : editorWindows)
		_editorWindow->Draw(renderer);
	Display();
}
void Engine::Window::EngineWindow::OnClear() const
{
	super::OnClear();
}
void Engine::Window::EngineWindow::OnReceiveEvent(const sf::Event& _event)
{
	super::OnReceiveEvent(_event);
	Manager::EventSystem::Instance()->Update(_event, renderer);
}
#pragma endregion

