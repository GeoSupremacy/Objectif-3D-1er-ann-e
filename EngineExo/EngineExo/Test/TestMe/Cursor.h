#pragma once
#include "../../Engine/UI/Element/UIElement.h"
#include "../../Engine/UI/Element/UIElement.h"
#include "../../Engine/UI/Interface/IPointerClickHandler.h"
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>


namespace Test
{
	class Cursor : public Engine::UI::UIElement, public IPointerClickHandler
	{
	
	private:
		sf::CircleShape circle = sf::CircleShape(75.f);
		float width = 50.f;
		float height = 400.f;
		int globalPositionR = 0;
		int mousePositionX = sf::Mouse::getPosition().x;
		int circlePosition = circle.getPosition().x;
		
	public:
		Cursor();
	public:
		void OnPointerClick(const sf::Event& _event)override;
		void OnPointerUnClick() override {}
		void Update();
	};
}

