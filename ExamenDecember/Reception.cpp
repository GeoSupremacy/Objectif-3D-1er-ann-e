#include "Reception.h"
#include "CreateNewBooking.h"
#include "BookingView.h"

#define CREATENEWBOOKING 4
#define VIEWBOOKING 7

#pragma region constructor/destructor
Reception::Reception()
{
#pragma region WNDCLASS

	const wchar_t* CLASS_NAME = L"Reception";

	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc_Internal;

	RegisterClass(&wndClass);
#pragma endregion WNDCLASS
#pragma region AdjustWindowRect
	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	int width = 1920;
	int height = 1080;

	//dimension window
	RECT rect;
	rect.left = 250;
	rect.top = 250;
	//Coordinate
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);
#pragma endregion AdjustWindowRect
#pragma region Window
	hWnd = CreateWindowEx(0,
		CLASS_NAME,
		L"Hotel Application",
		style,
		0,
		0,
		1920,
		1080,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	ShowWindow(hWnd, SW_SHOW);


	CreateWindowEx(WS_EX_TOPMOST, TEXT("Static"), TEXT("Hotel Objectif 3D"), BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 400, 0, 130, 20, hWnd, (HMENU)hInstance, NULL, NULL);
	CreateWindowEx(WS_EX_TOPMOST, TEXT("Button"), TEXT("Create new Booking"), BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 20, 40, 130, 20, hWnd, (HMENU)CREATENEWBOOKING, NULL, NULL);
	CreateWindowEx(WS_EX_TOPMOST, TEXT("Button"), TEXT("View all Bookings"), BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 200, 40, 130, 20, hWnd, (HMENU)VIEWBOOKING, NULL, NULL);
#pragma endregion Window
}
Reception::~Reception() {
	delete menu;
	menu = nullptr;
	delete instance;
	instance = nullptr;
}
#pragma endregion constructor/destructor
#pragma region method
LRESULT _stdcall Reception::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
	{
		switch (wParam)
		{
		case CREATENEWBOOKING:
			MoveCreatebooking();
			return 0;
		case VIEWBOOKING:
			MoveCreatebooking();
			return 0;
		}
	}
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

}
LRESULT _stdcall Reception::WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (WM_NCCREATE == _msg)
	{
		SetWindowLongPtr(_hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
		return true;
	}
	return reinterpret_cast<Reception*>(GetWindowLongPtr(_hWindow, GWLP_USERDATA))->WindowProc(_hWindow, _msg, _wp, _lp);
}
 void Reception::MoveCreatebooking()
{
	menu->DisplayMenu(2); //Pour aller à la class Createbooking
}
 void Reception::MoveViewBooking()
 {
	 menu->DisplayMenu(1); //Pour aller à la class ViewBooking
 }
Reception* Reception::getInstance()
{
	if (instance == nullptr)
	{
		
		instance = new Reception();

		
		return instance;
	}
	else
		return instance;
	
}
#pragma endregion method
