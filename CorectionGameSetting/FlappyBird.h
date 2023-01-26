#pragma once
#include "IGame.h"
#include "FlappyScore.h"
//h
#define SCREEN_WIDTH 60
#define SCREEN_WIDTH 26
#define SCREEN_HEIGHT 10
#define WIN_WIDTH 60
#define MENU_WIDTH 60
#define SLEEP_DEFAULT 100
#define PIPE = 7
#define PRESS_ANY_KEY "Press any key..."

class FlappyMap;
class FlappyPlayer;
class FlappyPipe;


class FlappyBird : public IGame
{
private:
	FlappyMap* map = nullptr;
	FlappyPlayer* player = nullptr;
	FlappyPipe* pipeOne = nullptr;
	FlappyPipe* pipeTwo = nullptr;
	FlappyScore* score = FlappyScore();
	bool isQuitting = false;
	int sleepTime = 0;
public:
	FlappyBird();
	~FlappyBird();
private:
	bool IsOutOfScreen() const;
	void Draw();
	void DisplayControle();
	void Clear();
	void UpdatePipe();
	void Init();
	void UpdtatScore();
public:
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	virtual void OnEnd() override;
	virtual void DisplayMenu() override;
	virtual std::string GameName()  const;
	virtual std::string GameDescription() const;

};

