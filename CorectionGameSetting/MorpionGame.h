#pragma once
#include "IGame.h"

class MorpionBoard;
class MorpionAI;

class MorpionGame : public IGame
{
private:
	MorpionBoard* board = nullptr;
	MorpionAI* ai = nullptr;
	int winner = 0;
	int currentPlayer = 1;
public:
	MorpionGame();
	~MorpionGame();
public:
	virtual void OnStart() override;
	virtual void OnStart() override;
	virtual void OnEnd() override;
	void OnUpdate();
	virtual void DisplayMenu() override;
	virtual std::string GameName() override;
	virtual std::string GamDescription() override;
	void PlayerTurn(const bool& _isPlayerTwo, int& _moves);
};

