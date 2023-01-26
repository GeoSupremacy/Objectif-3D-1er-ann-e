#pragma once
#include "Object.h"

class Igame;
class LauncherItem : public Object
{

private:
	Igame* game = nullptr;
public:
	LauncherItem() = default;
	LauncherItem(Igame* _game);
	LauncherItem(const LaungherItem& _copy);
	~LauncherItem() override;
public:
	void OnClick();
	void Display();
	Igame* Game();

};

