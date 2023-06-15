#pragma once
#include "../../Object/Object.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>


namespace Engine::PrimaryType
{
	class Vector2;
}
namespace Engine::Editor
{

	
	class EditorWindow :public Object
	{
		DECLARE_CLASS_INFO(EditorWindow, Object)
#pragma region f/p
	private:
		sf::RectangleShape titleShape = sf::RectangleShape();
		sf::Text titleText = sf::Text();
	protected:
		sf::RectangleShape* shape = nullptr;
#pragma endregion f/p
#pragma region constructor
	public:
		EditorWindow() = delete;
		EditorWindow(const char* _name);
#pragma endregion constructor
#pragma region constructor
	public:
		void Draw(sf::RenderWindow* _window);
		virtual void SetPosition(const PrimaryType::Vector2& _position);
		virtual void OnGUI();
		virtual void OnOpen();
#pragma endregion constructor

	};
}

