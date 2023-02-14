#pragma once
#include "BaseMenu.h"


class FB_Button;
class FB_Image;

class FB_MainMenu :public BaseMenu
{
#pragma region f/p
private:
	FB_Image* logoTilte = nullptr;
	FB_Image* background = nullptr;
	FB_Button* playButton = nullptr;
	FB_Button* scoreboardButton = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_MainMenu(Window* _owner);
	virtual ~FB_MainMenu() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void InitPlayButton();
	void InitLogoTitle();
	FB_Button* PlayButton() const;
	FB_Button* ScoreboardButton() const;
#pragma endregion methods
#pragma region override
public:
	 void Draw() override;
#pragma endregion override

};

