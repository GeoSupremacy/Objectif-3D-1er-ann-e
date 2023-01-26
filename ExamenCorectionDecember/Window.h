#pragma once
#include "Object.h"
#include "ButtonControl.h"
#include "BaseMenu.h"
#include <windows.h>
#include <CommCtrl.h>
#include <map>


#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")


class Window : public Object
{ 
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
	HWND windowInstance = nullptr;
	HINSTANCE hInstance = HINSTANCE();
	const wchar_t* title = TEXT("Default Window");
	int width = 1920;
	int height = 1080;
	bool isOpen = false;
	std::map<std::string, BaseMenu*> menus = std::map<std::string, BaseMenu*>();
	BaseMenu* currentMenu = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Window() = default;
	Window(const wchar_t* _title, int _width = 1920, int _height = 1080);
	~Window() override;
#pragma endregion constructor/destructor
#pragma region Proc
private:
	static LRESULT __stdcall WindowProcInternal(HWND _hWindows, UINT _msg, WPARAM _wp, LPARAM _lp);
	LRESULT __stdcall WindowProc(HWND _hWindows, UINT _msg, WPARAM _wp, LPARAM _lp);
#pragma endregion Proc
#pragma region methods
public:
	void RegisterMenu(BaseMenu* _menu);
	void SetCurrentMenu(const char* _menuName);
	void Open();
	void Close();
	void Update();
	HWND WindowInstance() const;
#pragma endregion methods
};

