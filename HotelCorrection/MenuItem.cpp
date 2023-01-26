#include "MenuItem.h"
#include "Menu.h"
MenuItem::MenuItem(const std::string& _name, const std::string& _description, Menu* _owner)
{
    name = _name;
    description = _description;
    nextMenu = _owner;
}

MenuItem::MenuItem(const MenuItem& _copy)
{
    name = _copy.name;
    description = _copy.description;
    nextMenu = _copy.nextMenu;
}

void MenuItem::OnCLick(Menu* _currentMenu)
{
    if (nextMenu == nullptr)
    {
        throw std::exception("[MenuItem] => next menu is null");

    }
    if (!nextMenu->Equals(_currentMenu))
        nextMenu->SetOldMenu(_currentMenu);
    _currentMenu->Close();

    nextMenu->Open();
}

std::string MenuItem::Name() const
{
    return name;
}

std::string MenuItem::Description() const
{
    return description;
}

Menu* MenuItem::Owner() const
{
    return nextMenu;
}

std::string MenuItem::ToString() const
{
    return name + "\n\t->" + description;
}
