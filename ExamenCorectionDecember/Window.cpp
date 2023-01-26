#include "Window.h"
#include "BaseMenu.h"
#include "ButtonControl.h"
#include "TextFieldControl.h"
#include <format>
#include <map>

#pragma region constructor/destructor
Window::Window(const wchar_t* _title, int _width, int _height)
{
	title = _title;
	width = _width;
	height = _height;

	INITCOMMONCONTROLSEX __iccex;
	__iccex.dwSize = sizeof(__iccex);
	__iccex.dwICC = ICC_DATE_CLASSES;

	if (!InitCommonControlsEx(&__iccex))
		throw std::exception("[Window] =>failed common control!");

	hInstance = GetModuleHandle(NULL);
	LPCWSTR _className = TEXT("Sample Window Class");
	WNDCLASS _wndClass = {};
	_wndClass.style = CS_HREDRAW | CS_VREDRAW;
	_wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	_wndClass.lpszClassName = _className;
	_wndClass.hInstance = hInstance;
	_wndClass.lpfnWndProc = WindowProcInternal;
	RegisterClass(&_wndClass);

	windowInstance = CreateWindowEx(WS_EX_APPWINDOW, _className, title, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr, hInstance, this);

	std::wstring _wstr = title;
	std::string _tilteCstr(_wstr.begin(), _wstr.end());
	SetWindowTextA(windowInstance, _tilteCstr.c_str());
}
Window::Window() {
	for (BaseMenu* menu : menus | std::ranges::view::values)
		delete menu;
	
	if (isOpen)
		Close();
}
#pragma endregion constructor/destructor
#pragma region Proc
LRESULT __stdcall Window::WindowProcInternal(HWND _hWindows, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (_msg == WM_NCCREATE)
	{
		SetWindowLongPtr(_hWindows, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
		return true;
	}
	return reinterpret_cast<Window*>(GetWindowLongPtr(_hWindows, GWLP_USERDATA))->WindowProc(_hWindows, _msg, _wp, _lp);
}
LRESULT __stdcall Window::WindowProc(HWND _hWindows, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (_hWindows == nullptr) return false;
	switch (_msg)
	{
	case WM_CREATE:
	{
		ButtonControl _b1 = ButtonControl(0, windowInstance, Rect(10, 10, 150, 20), TEXT("Text"));
		_b1.Create();
		ButtonControl _b2 = ButtonControl(0, windowInstance, Rect(10, 40, 150, 20), TEXT("Text"));
		_b2.Create();
	}
	case WM_COMMAND:
	{
		if (!ButtonControl::buttons.contains(_wp)) break;
		ButtonControl::buttons[_wp]->Onclick.Invoke();
		break;
		WORD _word = HIWORD(_wp);
		switch (_word)
		{
		case EN_CHANGE:
			std::map<int, TextFieldControl*> textfields = TextFieldControl::textfields;
			for (std::map<int, TextFieldControl*> _pair : textfields)
			{
				if (_pair.first == LOWORD(_wp))
				{

				}
			}
		default:
			break;
		}
	}
	case WM_DESTROY:
	{
		isOpen = false;
		exit(0);
		break;
	}
	}
	return DefWindowProc(_hWindows, _msg, _wp, _lp);
}
#pragma endregion Proc
#pragma region methods
void Window::RegisterMenu(BaseMenu* _menu)
{
	if (menus.contains(_menu->Name()))return;
	if (!_menu->IsInitialized())
		_menu->Initialized();
	menus.insert(std::pair(_menu->Name().c_str(), _menu));
}
void Window::SetCurrentMenu(const char* _menuName)
{
	if (!menus.contains(_menuName))
		throw std::exception(std::format("[Window] => () doesn't exit, _menuName").c_str());
	if (currentMenu != nullptr)
		currentMenu->Close();
	currentMenu = menus[_menuName];
	currentMenu->Open();
}
void Window::Open()
{
	if (windowInstance == nullptr)
		throw std::exception("[Window] => window instance is null");
	ShowWindow(windowInstance, SW_NORMAL);
	UpdateWindow(windowInstance);
	isOpen = true;
	Update();
}
void Window::Close()
{
	if (windowInstance == nullptr || !isOpen)
		throw std::exception("[Window] => window instance is null or not open");
	isOpen = false;
}
void Window::Update()
{
	MSG msg = {};
	while (isOpen)
	{
		while (PeekMessage(&msg, windowInstance, 0, 0, PM_REMOVE))
		{
			if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}
}
HWND Window::WindowInstance() const
{
	return HWND();
}
#pragma endregion methods





