#pragma once
#include "../Element/UIElement.h"
#include "../../UI/Interface/IPointerMoveHandler.h"
#include "../../Event/Action/Action.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace Engine::UI
{
	class Slider :public UIElement, public IPointerMoveHandler
	{
		DECLARE_CLASS_INFO(Slider, UIElement)
	private:
		sf::CircleShape* handle = nullptr;
		sf::RectangleShape* box = nullptr;
		float minValue = 0.0f;
		float maxValue = 100.0f;
		int currentValue = 0;
		Action<float> OnValueChanged = nullptr;

	public:
		Slider();
		Slider(float _min, float _max, float _value);
		Slider(float _value);
		~Slider() override;

	private:
		void UpDateHandlePosition();
	public:
		void SetValue(float _value);
		void SetMin(float _min);
		void SetMax(float _max);
	public:
		void Draw(sf::RenderWindow* _window) override;
		void SetPosition(const PrimaryType::Vector2& _position) override;
		void OnPointerMove(float _x, float _y) override;
	};
}

