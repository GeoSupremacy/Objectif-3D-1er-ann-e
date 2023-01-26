#include <iostream>
#include "CreateNewBooking.h"


#define RETURN 0
#define CREATE 9

#pragma region constructor/destructor
CreateNewBooking::CreateNewBooking()
{
#pragma region WNDCLASS
	const wchar_t* CLASS_NAME = L"Create New Booking";
	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = hInstance;
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


	CreateWindowEx(WS_EX_TOPMOST, TEXT("Static"), TEXT("Create new Booking"), BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 400, 0, 130, 20, hWnd, (HMENU)CREATE, NULL, NULL);
	CreateWindowEx(WS_EX_TOPMOST, TEXT("Button"), TEXT("Return"), BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 200, 40, 130, 20, hWnd, (HMENU)RETURN, NULL, NULL);

	/* Des boutons pour nom,prénom ,nombre de personne est le calendrier => qui sont des text box*/
#pragma endregion Window
}
CreateNewBooking::~CreateNewBooking() {
	delete menu;
	delete instance;
	menu = nullptr;
	instance = nullptr;
}
#pragma endregion constructor/destructor
#pragma region method
CreateNewBooking* CreateNewBooking::getInstance()
{
	if (instance == nullptr)
	{
		instance = new CreateNewBooking();

		return instance;
	}
	else
		return instance;
	
}
 void CreateNewBooking::MoveMenu()
{
	menu->DisplayMenu(0); //retour  à la réception
}
 void CreateNewBooking::CreateBooking()
 {
	/*
	* Convertire les texbox en d'autre type pour les stocker dans la class 'Réserve'
	 Utilse la méthode CreatNode de 'Réserve' pour créer le bouton
	 */
 }
 LRESULT _stdcall CreateNewBooking::WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
 {
	 if (WM_NCCREATE == _msg)
	 {
		 SetWindowLongPtr(_hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
		 return true;
	 }
	 return reinterpret_cast<CreateNewBooking*>(GetWindowLongPtr(_hWindow, GWLP_USERDATA))->WindowProc(_hWindow, _msg, _wp, _lp);
 }
 LRESULT _stdcall CreateNewBooking::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
 {

	 switch (uMsg)
	 {
	 case WM_COMMAND:
	 {
		 switch (wParam)
		 {
		 case RETURN:
			 MoveMenu();
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
#pragma endregion method
