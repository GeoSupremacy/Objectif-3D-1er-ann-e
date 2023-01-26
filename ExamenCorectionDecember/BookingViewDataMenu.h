#pragma once
#include "BaseMenu.h"


class LabelControle;
class CalendarControle;

class BookingViewDataMenu :public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)
#pragma region f/p
private:
	LabelControle* firstName = nullptr;
	LabelControle* lastName = nullptr;
	LabelControle* numberOfPeople = nullptr;
	CalendarControle * calendar = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	BookingViewDataMenu() = default;
	BookingViewDataMenu(BookingViewDataMenu& _copy) = default;
	BookingViewDataMenu(Window& _owner);
#pragma endregion constructor/destructor
#pragma region methods
public:
	std::string TextStr();
	std::wstring Text();
	void SetText(const wchar_t* _newText);
	void SetText(const std::string& _str);
#pragma endregion methods
#pragma region override
public:
	 bool IsInitialized() const override;
	 void Open() override;
	 void Close() override;
	 void Initialized() override;
	 void Initialize() override;
#pragma endregion override

};

