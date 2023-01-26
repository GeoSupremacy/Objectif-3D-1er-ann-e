#pragma once
#include "WindowControl.h"
#include "Delegate.h"
#include "Rect.h"
#include <map>

class ButtonControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)
#pragma region f/p
public:
	Delegate<void>* Onclick = nullptr;
private:
	const wchar_t* text = TEXT("Default");
public:
	static inline std::map<int, ButtonControl*> buttons = std::map<int, ButtonControl*>();
#pragma endregion f/p
#pragma region constructor/destructor
public:
	ButtonControl() = default;
	ButtonControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text);
	ButtonControl(const ButtonControl& _copy);
#pragma endregion constructor/destructor
#pragma region override
public:
	HWND Create() override;
#pragma endregion override
public:
	
};

