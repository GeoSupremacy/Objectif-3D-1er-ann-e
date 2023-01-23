

class IGame;
class LauncherItem 
{

private:
	IGame* game = nullptr;
public:
	LauncherItem() = default;
	LauncherItem(IGame* _game);
	LauncherItem(const LauncherItem& _copy);
	//~LauncherItem() override;
public:
	void OnClick();
	void Display();
	IGame* Game();

};


