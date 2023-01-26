#include "CalendarControl.h"
#include <calendardeviceservice.h>

#pragma region constructor/destructor
CalendarControl::CalendarControl(int _controlID, HWND _owner, const Rect& _rect) : super(_controlID, _owner, _rect) {}
CalendarControl::CalendarControl(const CalendarControl& _copy) :super(_copy) {}
#pragma endregion constructor/destructor
#pragma region methods
void CalendarControl::SetMaxSelected(UINT _value)
{

	if (!isInitialised) return;
	MonthCal_SetMaxSelCount(instance, _value);
}

void CalendarControl::SetValue(const DateTime& _a, const DateTime& _b)
{
	const SYSTEMTIME _start = _a.ToSystemTime();
	const SYSTEMTIME _end = _b.ToSystemTime();
	LPSYSTEMTIME _tab = new SYSTEMTIME[2]{ _start, _end};
	MonthCal_SetSelRange(instance, _tab);
}										  
void CalendarControl::OnChoise(LPNMSELCHANGE _value)
{
	arrivedDate = _value;
	departureData = _value;
}
#pragma endregion methods
#pragma region override
HWND CalendarControl::Create()
{
	instance = CreateWindowEx(0, MONTHCAL_CLASS, WS_BORDER | WS_CHILD | WS_VISIBLE | MCS_DAYSTATE | MCS_NOTODAY | NCS_MULTISELECT,
		rect.X(), rect.Y(), rect.Width(), rect.Height(),owner, (HMENU)contolrID,ownerInstance,nullptr);

	RECT _minRect = {};
	MonthCal_GetMinReqRect(instance, &_minRect);
	SetWindowPos(instance, NULL, rect.X(), rect.Y(), _minRect.right, _minRect.bottom, SWP_NOZORDER);
	MonthCal_SetCurrentView(instance, MCMV_MONTH);

	//SYSTEMTIME* _times = new  SYSTEMTIME();
	if (instance != NULL)
	{
		isInitialised = true;
		Show();
	}
	return instance;
}
#pragma endregion override
