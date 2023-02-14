#pragma once
#include "BaseMenu.h"
#include "FB_Label.h"

class FB_GameOverMenu : public BaseMenu
{
#pragma region f/p
private:
	class FB_Image* gameOverImage = nullptr;
	FB_Image* titleImage = nullptr;
	class FB_Button* restartButton = nullptr;
	FB_Label* scoreText = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_GameOverMenu(Window* _owner);
	virtual ~FB_GameOverMenu() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void InitRestartButton(const float _width, const float _height);
	void InitGameOverImage(const float _width, const float _height);
	void InitTitleImage(const float _width);
	void InitScoreText(const float _with, const float _height);
	FB_Button* RestartButton()const;
#pragma endregion methods
#pragma region override
public:
	virtual void Draw() override;
#pragma endregion override
};

