#include "EditorWindow.h"
#include "../../Manager/FontManager.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../WIndow/Engine/EngineWindow.h"

Engine::Editor::EditorWindow::EditorWindow(const char* _name): super()
{
	titleShape = sf::RectangleShape(Engine::PrimaryType::Vector2(60, 20));
	titleShape.setFillColor(sf::Color(50, 50, 50, 255));
	titleText = sf::Text(_name, *Manager::FontManager::Instance()->GetFont("Arial"));
	titleText.setCharacterSize(12);

	const int _height = Window::EngineWindow::Instance()->Height();
	shape = new sf::RectangleShape(sf::Vector2f(20, 20));
}
Engine::Editor::EditorWindow::EditorWindow(const EditorWindow& _copy) : super(_copy)
{
	titleShape = _copy.titleShape;
	titleText = _copy.titleText;
	shape = _copy.shape;
}


void Engine::Editor::EditorWindow::Draw(sf::RenderWindow* _window)
{
	_window->draw(*shape);
	_window->draw(titleShape);
	_window->draw(titleText);
}
void Engine::Editor::EditorWindow::SetPosition(const PrimaryType::Vector2& _position)
{
	shape->setPosition(_position);
	titleShape.setPosition(PrimaryType::Vector2(_position.x, _position.y - titleShape.getGlobalBounds().height));
	const sf::FloatRect _shapeBounds = shape->getGlobalBounds();
	const sf::FloatRect _textBounds = titleText.getGlobalBounds();
	const float _x = _shapeBounds.left + (_shapeBounds.width/2) - (_textBounds.width/2);
	const float _y = _shapeBounds.top + (_shapeBounds.height / 2) - (_textBounds.height / 2);
	titleText.setPosition(_x, _y);
}
void Engine::Editor::EditorWindow::OnGUI(){ }
void Engine::Editor::EditorWindow::OnOpen()
{
	Window::EngineWindow::Instance()->RegisterEditorWindow(this);
}
