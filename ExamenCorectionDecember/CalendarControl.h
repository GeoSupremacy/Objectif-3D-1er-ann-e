#pragma once
#include "DateTime.h"
#include "WindowControl.h"
#include <CommCtrl.h>
#include <map>


class CalendarControl :public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)
#pragma region f/p
public:
	static inline std::map<int, CalendarControl*> calendar = std::map<int, CalendarControl*>();
private:
	DateTime  arrivedDate  =  DateTime();
	DateTime departureData =  DateTime();
#pragma endregion f/p
#pragma region constructor/destructor
public:
	CalendarControl(int _controlID, HWND _owner, const Rect& _rect);
	CalendarControl(const CalendarControl& _copy);
#pragma endregion constructor/destructor
#pragma region methods
public:
	void SetMaxSelected(UINT _value);
	void SetValue(const DateTime& _a, const DateTime& _b);
	void OnChoise(LPNMSELCHANGE _value);
#pragma endregion methods
#pragma region override
public:
	HWND Create() override;
#pragma endregion override

};

