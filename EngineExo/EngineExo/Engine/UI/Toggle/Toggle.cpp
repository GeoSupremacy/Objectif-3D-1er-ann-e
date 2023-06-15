#include "Toggle.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../Manager/Texture/TextureManager.h"
#include <SFML/Graphics/RectangleShape.hpp>


#pragma region constructor
Engine::UI::Toggle::Toggle() : super() 
{ 
	shape = new sf::RectangleShape(sf::Vector2f(150, 150));
	toggleFalseTexture = Manager::TextureManager::Instance()->GetTexture(TOGGLE_INVALID_NAME);
	toggleTrueTexture = Manager::TextureManager::Instance()->GetTexture(TOGGLE_VALID_NAME);
	shape->setTexture(toggleFalseTexture);
	
}
Engine::UI::Toggle::Toggle(bool _status) : self()
{
	SetStatus(_status);
	
}
Engine::UI::Toggle::Toggle(const Toggle& _copy) : super(_copy)
{
	status = _copy.status;
	toggleTrueTexture = _copy.toggleTrueTexture;
	toggleFalseTexture = _copy.toggleFalseTexture;
	SetStatus(status);
}
#pragma endregion constructor
#pragma region method
void Engine::UI::Toggle::SetStatus(bool _status)
{
	status = _status;
	shape->setTexture(status ? toggleTrueTexture : toggleFalseTexture);
}
#pragma endregion method
#pragma region override
void Engine::UI::Toggle::OnPointerClick(const sf::Event& _event)
{
	SetStatus(!status);
}
#pragma endregion override