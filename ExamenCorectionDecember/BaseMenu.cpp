#include "BaseMenu.h"
#include "WindowControl.h"
#include "LabelControl.h"
#include "TextFieldControl.h"
#include "Windows.h"

#include <powerbase.h>


#pragma region constructor/destructor
BaseMenu::BaseMenu(Window* _owner, const char* _name): super()
{
	owner = _owner;
	name = _name;
}
BaseMenu::BaseMenu(const BaseMenu& _copy):super(_copy)
{
	owner = _copy.owner;
	name = _copy.name;
}
#pragma endregion constructor/destructor
#pragma region methods
bool BaseMenu::IsInitialized() const
{
	return isInitialized;
}
void BaseMenu::Open()
{
	if (!isInitialized)return;
	for (WindowControl* _control : controls)
		_control->Show();
}
void BaseMenu::Close()
{
	if (!isInitialized)return;
	for (WindowControl* _control : controls)
		_control->Hide();
}
void BaseMenu::Initialized()
{
	std::string _str = name;
	const int _width = (owner->Width() / 2) - (std::pow(_str.length() / 2, 2);
	const std::wstring _WName(_str.begin(), _str.end());
	CreateLabel(Rect(_width,0,255,20)_WName);
	isInitialized = true;
}
std::string BaseMenu::Name() const
{
	return name;
}
void BaseMenu::CreateTextField(const Rect& _rect, const wchar_t* _text)
{
	TextFieldControl* textField = new TextFieldControl();
}
ButtonControl* BaseMenu::CreateButton(const Rect& _rect, const wchar_t* _text)
{
	ButtonControl* _button = new ButtonControl(currentControlID++, owner->WindowInstance(), _rect, _text);
	_button->Create();
	controls.push_back(_button);
	
}
void BaseMenu::CreateLabel(const Rect& _rect, const wchar_t* _text)
{
	LabelControl* _button = new LabelControl(currentControlID++, owner->WindowInstance(), _rect, _text);
	_button->Create();
	controls.push_back(_button);
}
CalendarControl* BaseMenu::CreateCalendar(const Rect& _rect)
{
	CalendarControl* _calendar = new CalendarControl(currentControlID++, owner->WindowInstance(), _rect);
	_calendar->Create();
	controls.push_back(_calendar);
	return _calendar;
}
void BaseMenu::Initialize()
{
	std::string _str = name;
	const int _width = (owner->Width() / 2) - (std::pow(_str.lenght() / 2, 2);
	const std::wstring _WsName(_str.begin(), _str.end());
	CreateLabel(Rect(_width, 0, 255, 20), _WsName.c_str());
}
#pragma endregion methods


