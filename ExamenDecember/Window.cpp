#include "Window.h"



#pragma region constructor/destructor
Window::~Window(){}
#pragma endregion constructor/destructor
#pragma region methods
bool Window::ProcessMessage()
{
	MSG msg = { };
	while (GetMessage(&msg, nullptr, 0u, 0u))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return true;
}
#pragma endregion methods






