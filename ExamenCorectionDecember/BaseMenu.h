#pragma once
#include "Object.h"
#include "ButtonControl.h"
#include <vector>

class WindowControl;
class Window;
class Rect;
class CalendarControl;

class BaseMenu :public Object
{
    DECLARE_CLASS_INFO(Object)
#pragma region f/p
protected:
    static inline int currentControlID = 0;
    const char* name = "";
    bool isInitialized = false;
    Window* owner = nullptr;
    std::vector<WindowControl*> controls = std::vector<WindowControl*>();
#pragma endregion f/p
#pragma region constructor/destructor
public:
    BaseMenu() = default;
    BaseMenu(Window* _owner, const char* _name);
    BaseMenu(const BaseMenu& _copy);
#pragma endregion constructor/destructor
#pragma region methods
public:
    virtual bool IsInitialized() const;
    virtual void Open();
    virtual void Close();
    virtual void Initialized();
    virtual void Initialize();
    std::string Name() const;
protected:
    void CreateTextField(const Rect& _rect, const wchar_t* _text);
    ButtonControl* CreateButton(const Rect& _rect, const wchar_t* _text);
    void CreateLabel(const Rect& _rect, const wchar_t* _text);
    CalendarControl* CreateCalendar(const Rect& _rect);
#pragma endregion methods

};

