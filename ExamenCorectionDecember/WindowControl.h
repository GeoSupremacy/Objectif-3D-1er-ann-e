#pragma once
#include "Object.h"
#include "Rect.h"
#include <windows.h>

class WindowControl :
    public Object
{
    DECLARE_CLASS_INFO(Object)
#pragma region f/p
    protected:
    int controlID = 0;
    HWND owner = nullptr;
    HWND instance = nullptr;
    HINSTANCE ownerInstance;
    bool isInitialised = false;
    bool isShow = true;
    Rect* rect;
#pragma endregion f/p
#pragma region constructor/destructor
public:
    WindowControl() = default;
    WindowControl(int _controlID, HWND _owner, Rect& _rect);
    WindowControl(const WindowControl& _copy);
#pragma endregion constructor/destructor
#pragma region methods
    public:
    void Show();
    void Hide();
    bool IsInitialized()const;
protected:
    virtual HWND Create();
#pragma endregion methods

};

