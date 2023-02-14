#pragma once
#include <SFML/Graphics.hpp>

class BaseMenu;

class Window
{
#pragma region f/p
protected:
	float width = 900;
	float height = 800;
	const char* title = "Default Window";
	sf::RenderWindow* window = nullptr;
	std::map<const char*, BaseMenu*> menus = std::map<const char*, BaseMenu*>();
protected:
	bool eventIfNotFocus = false;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Window() = default;
	Window(const float _width, const float _height, const char* _title);
	Window(const Window& _copy) = delete;
	virtual ~Window();
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Update();
public:
	int Width();
	int Height();
	void Open();
	void Close();
	bool IsOpen() const;
	bool HasFocus()const;
	void SetFrameLimit(const int _frame);
	void Draw(sf::Drawable* _drawable);
	sf::RenderWindow* Renderer() const;
protected:
	void CloseAllMenus();
	void OpenMenu(const char* _name);
	void RegisterMenu(const char* _name, BaseMenu* _menu);
	virtual void InitMenu();
	virtual void OnDraw() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnReceiveEvent(const sf::Event& _event);
#pragma endregion methods
};

