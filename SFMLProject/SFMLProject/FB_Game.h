#pragma once
#include "Window.h"
#include "FB_Image.h"

#define TIME_FOR_SPAWN .5f
#define GAP 150
class FB_Bird;

class FB_Game :public Window
{
private:
	bool isStarted = false;
	FB_Image* background = nullptr;
	class FB_Bird* bird = nullptr;
	class FB_Score* score = nullptr;
	sf::Clock spawnerClock = sf::Clock();
#pragma region constructor/destructor
public:
	FB_Game();
	~FB_Game() override;
#pragma endregion constructor/destructor
#pragma region methode
private:
	void OnBirdDie();
	void Start();
	void SpawnPipe();
	void InitBackGround();
#pragma endregion methode
#pragma region override
public:
	void OnDraw() override;
	void OnUpdate() override;
	void InitMenu() override;
#pragma endregion override
};

