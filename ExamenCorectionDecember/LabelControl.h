#pragma once
#include "WindowControl.h"
#include "Rect.h"

class LabelControl : public WindowControl
{
    DECLARE_CLASS_INFO(WindowControl)
#pragma region f/p
private:
    const wchar_t* text = TEXT("");
#pragma endregion f/p
#pragma region constructor/destructor
public:
    LabelControl() = default;
    LabelControl(int _controleID, HWND _owner), Rect &_rect, const wchar_t* _text);
#pragma endregion constructor/destructor
#pragma region methods
public:
    void SetText(const wchar_t* _nexText);
    std::string TextStr();
    std::wstring Text();
#pragma endregion methods
#pragma region override
public:
    HWND Create() override;
#pragma endregion override
};

