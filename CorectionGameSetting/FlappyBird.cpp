#include "FlappyBird.h"
#include "FlappyMap.h"
#include "FlappyPlayer.h"
#include "FlappyPipe.h"
#include "Utils.h"
#pragma region C/D
FlappyBird::FlappyBird()
{
	map = new FlappyMap();
	player = new FlappyPlayer();
	pipeOne = new FlappyPipe();
	pipeTwo = new FlappyPipe();

}
FlappyBird::~FlappyBird()
{
	map = nullptr;
	player = nullptr;
}
#pragma endregion C/D
#pragma region Methode
void FlappyBird::Draw()
{
	map->Draw();

}
void FlappyBird::DisplayControle()
{
	Utils::SetCursor(WIN_WIDTH + 5, 2);
	Utils::LogWithEffect(GameName());
	Utils::SetCursor(WIN_WIDTH + 6, 4);
	Utils::LogWithEffect("----------");
	Utils::SetCursor(WIN_WIDTH + 6, 6);
	Utils::LogWithEffect("----------");
	Utils::SetCursor(WIN_WIDTH + 7, 12);
	Utils::LogWithEffect("Control");
	Utils::SetCursor(WIN_WIDTH + 7, 13);
	Utils::LogWithEffect("-------- ");
	Utils::SetCursor(WIN_WIDTH + 7, 14);
	Utils::LogWithEffect("Spacebar for msg");
}
void FlappyBird::Init()
{
	isQuitting = false;
	score = 0;
	player->SetDead(false);
	player->SetPosition(6);
	pipeOne->SetCanDraw(true);
	pipeTwo->SetCanDraw(false);
	pipeOne->SetPosition(4);
	pipeTwo->SetPosition(4);
	pipeOne->SetGapPosition(3 + rand() % 14);
}
void FlappyBird::UpdtatScore()
{
	if (pipeOne->Position() > 68)
		pipeTwo->SetCanDraw(false);
}
bool FlappyBird::IsOutOfScreen() const
{
	const int _position;
	if (_position <= 3)
	{
	}
}
void FlappyBird::Clear()
{
}
void FlappyBird::UpdatePipe()
{
	pipeOne->Update();
	pipeTwo->Update();

	const int _pipePosition = pipeOne->Position();
	if (_pipePosition >= 40 && _pipePosition < 42)
	{

		pipeTwo->SetCanDraw(true);
		pipeTwo->SetPosition(4);
		pipeTwo->SetGapPosition(3 + rand() % 14);
	}
}
#pragma region Methode

void FlappyBird::OnStar()
{
	Utils::SetWindowSize(SCREEN_WIDTH * 10, SCREEN_HEIGHT * 20);
	Utils::ClearConsole();
	Utils::SetCursor(false, 0);
	sleepTime = SLEEP_DEFAULT;
	map->Draw();
}
void FlappyBird::OnUpdate()
{
	while (!player->IsDead() && !isQuitting)
	{
		const char _input = Utils::CinNoBlock();
		if (_input == SPACE) player->Jump();
		else if (_input == ESCAPE)
		{
			isQuitting = true;
			continue;
		}
		Draw();
		

		if (player->IsCollide(pipeOne))
		{
			player->SetDead(true);
			continue;
		}

		Utils::Sleep(sleepTime);
		Clear();
		player->Update();
	}
}
void FlappyBird::OnEnd()
{
	player->Draw();
	Utils::SetCursorPosition(15, 5);
	std::cout << "SCORE: " << score;
	Utils::SetCursorPosition(10, 5);
	std::cout << PRESS_ANY_KEY;
	_getch();
	Utils::SetCursor(true, 20);
}
void FlappyBird::DisplayMenu()
{
	DisplayConsole();
	score->Draw();
	Utils::SetCursorPosition(10, 5);
	std::cout << Utils::LogSeparator(strlen(PRESS_ANY_KEY), ' ');

}
std::string FlappyBird::GameName() const
{
	"Flappy";
}
std::string FlappyBird::GameDescription() const
{
	"FlappyBird";

}
