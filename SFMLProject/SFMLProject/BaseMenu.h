#pragma once
#include "Object.h"
#include <vector>


class BaseMenu : public Object
{
#pragma region f/p
protected:
	std::vector<class FB_UIElement*> elements = std::vector<class FB_UIElement*>();
	bool isOpen = false;
	class Window* owner = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	BaseMenu(Window* _owner);
	virtual ~BaseMenu() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void SetActive(const bool _statu);
public:
	void Open();
	void CLose();
	virtual void Draw();
#pragma endregion methods
};

