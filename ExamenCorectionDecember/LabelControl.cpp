#include "LabelControl.h"

#pragma region constructor/destructor

#pragma endregion constructor/destructor
#pragma region methods
std::string LabelControl::TextStr()
{
    const std::wstring _text = Text();
    return std::string(_text.begin(), _text.end());
}

std::wstring LabelControl::Text()
{
    return text;
}
void LabelControl::SetText(const wchar_t* _nexText)
{
    text = _nexText;
}

#pragma endregion methods
#pragma region override
HWND LabelControl::Create()
{
    instance = CreateWindowEx(0, L"STATIC", text, WS_CHILD | WS_VISIBLE, rect->X(), rect->Width(), rect->Height(), owner, (HMENU)controlID, ownerInstance, nullptr);


    return instance;
}
#pragma endregion override

