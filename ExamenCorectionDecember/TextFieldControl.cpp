#include "TextFieldControl.h"


#pragma region constructor/destructor
TextFieldControl::TextFieldControl(int _controlID, HWND _owner, Rect _rect, const wchar_t* _defaultText) : super(_controlID, _rect, _owner)
{
	defaultText = _defaultText;

}
TextFieldControl::TextFieldControl(const TextFieldControl& _copy) : super(_copy){}
#pragma endregion constructor/destructor
#pragma region methods
void TextFieldControl::OnValueChange()
{
	const int _length = GeWindowTextLength(instance) + 1;
	char* _array = new char[_length];
	GetWindowTextA(instance, &_array[0], _length);
	std::string _result = _array;
	//currentText = std::wstring(_result, 
}
std::wstring TextFieldControl::CurrentText() const
{
	return currentText;
}
std::string TextFieldControl::CurrentTextStr() const
{
	return std::string(currentText.begin(), currentText.end());
}
void TextFieldControl::OnTextChange(const wchar_t* _text)
{
	currentText = _text;
}
#pragma endregion methods
#pragma region overrid
HWND TextFieldControl::Create()
{
	instance = CreateWindowEx(0, TEXT("EDIT"), defaultText, WS_CHILD | WS_VISIBLE,(HMENU)controlID, ownerInstance, nullptr);

	if (instance  != NULL)
	{
		isInitialised = true; 
		textfields.insert(std::pair(controlID, this));
		Show();
	}
}

#pragma endregion override




