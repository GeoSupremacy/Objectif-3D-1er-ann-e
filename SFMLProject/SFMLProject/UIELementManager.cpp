#include "UIELementManager.h"
#include "FB_UIElement.h"


void UIElementManager::Register(FB_UIElement* _elements)
{
	elements.push_back(_elements);
}
void UIElementManager::UnRegister(FB_UIElement* _elements)
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
	{
		elements.erase(elements.begin() + i);
		break;
	}
}
void UIElementManager::Update()
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
		elements[i]->OnUpdate();
}
void UIElementManager::OnDestroy()
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
		delete elements[i];
	elements.clear();
}
