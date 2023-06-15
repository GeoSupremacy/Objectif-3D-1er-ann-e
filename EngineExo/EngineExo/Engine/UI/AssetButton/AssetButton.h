#pragma once
#include "../Element/UIElement.h"
#include "../Interface/IPointerClickHandler.h"
#include "../Interface/IPointerEnterHandler.h"
#include "../Interface/IPointerExitHandler.h"
#include "../../Event/Action/Action.h"

namespace Engine::UI
{
	class AssetButton :public UIElement, public IPointerClickHandler, public  IPointerEnterHandler, public IPointerExitHandler
	{
		DECLARE_CLASS_INFO(AssetButton, UIElement)

	private:
		float width = 100.0f;
		float height = 40.0f;
		sf::Text text = sf::Text();
		sf::Color baseColor = sf::Color::White;
		sf::Color enterColor = sf::Color(189, 195, 199);
		Object* object = nullptr;
		Action<Object*>OnCLick = nullptr;
	public:
		AssetButton() = delete;
		AssetButton(const std::string& _text, float _width, float _height, Object* _object, const Action<Object*>& _onCLick = nullptr);
	public:
		template<typename Class>
		void AddListener(Class* _instance, void (Class::* ptr)(Object*))
		{
			OnCLick.AddDynamic(_instance, ptr);
		}
		template<typename Class>
		void RemoveListenet(Class* _instance, void (Class::* ptr)(Object*))
		{
			OnCLick.RemoveDynamic(_instance, ptr);
		}
		void SetBackGroundColor(const sf::Color& _color);
	public:
		void OnPointerClick(const sf::Event& _event) override;
		void OnPointerUnClick() override {}
		void OnPointerEnter() override;
		void OnPointerExit() override;
		void SetPosition(const PrimaryType::Vector2 &_position) override;
		void Draw(sf::RenderWindow* _window) override;
};

}

