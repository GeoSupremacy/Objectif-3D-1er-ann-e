#include "Object.h"

class Menu;
class MenuItem : public Object
{
private:
	std::string name = "";
	std::string description = "";
	Menu* nextMenu = nullptr;
public:
	MenuItem() = default;
	MenuItem(const std::string& _name, const std::string& _description, Menu* _owner);
	MenuItem(const MenuItem& _copy);
	~MenuItem() override= default;
public:
	void OnCLick(Menu* _currentMenu);
	std::string Name() const;
	std::string Description() const;
	Menu* Owner() const;

public:
	std::string ToString() const override;
};

