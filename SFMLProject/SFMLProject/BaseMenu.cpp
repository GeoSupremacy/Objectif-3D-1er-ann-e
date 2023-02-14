#include "BaseMenu.h"
#include "FB_UIElement.h"

#pragma region constructor/destructor
BaseMenu::BaseMenu(Window* _owner)
{
	owner = _owner;
}
BaseMenu::~BaseMenu()
{
	const size_t  _size = elements.size();
	for (size_t i = 0; i < _size; i++)
		delete elements[i];
	elements.clear();
}
#pragma endregion constructor/destructor
#pragma region methods
void BaseMenu::Open()
{
	isOpen = true;
	SetActive(true);
}
void BaseMenu::CLose()
{
	isOpen = false;
	SetActive(false);
}
void BaseMenu::SetActive(const bool _statu)
{
	const size_t  _size = elements.size();
	for (size_t i = 0; i < _size; i++)
		elements[i]->SetActive(_statu);
}
void BaseMenu::Draw()
{
	const size_t  _size = elements.size();
	for (size_t i = 0; i < _size; i++)
		elements[i]->Draw(owner);
}
#pragma endregion methods