#include "WindowControl.h"
#include <ctime>


#pragma region constructor/destructor
WindowControl::WindowControl(int _controlID, HWND _owner, Rect& _rect): super()
{
	controlID = _controlID;
	owner = _owner;
	ownerInstance = (HINSTANCE)GetWindowLongPtr(owner, GWLP_HINSTANCE);
	rect = &_rect;
}
WindowControl::WindowControl(const WindowControl& _copy)
{
	controlID = _copy.controlID;
	owner = _copy.owner;
	ownerInstance = _copy.ownerInstance;
	rect = _copy.rect;
}
#pragma endregion constructor/destructor
#pragma region methods
void WindowControl::Show()
{
	if (!isInitialised) return;
	ShowWindow(instance, true);
	isShow = true;
}
void WindowControl::Hide()
{
	if (!isInitialised) return;
	ShowWindow(instance, false);
	isShow = false;
}
bool WindowControl::IsInitialized() const
{
	return isInitialised;
}
HWND WindowControl::Create()
{
	return (HWND)NULL;
}
#pragma endregion methods
