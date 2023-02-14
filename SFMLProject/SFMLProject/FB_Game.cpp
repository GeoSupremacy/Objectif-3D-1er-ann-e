#include "FB_Game.h"
#include "FB_MainMenu.h"
#include "BaseMenu.h"
#include "FB_Button.h"
#include "FB_GameObjectManager.h"
#include <iostream>
#include "FB_Pipe.h"
#include "FB_Bird.h"
#include "FB_Score.h"
#include "FB_GameOverMenu.h"

#pragma region constructor/destructor
FB_Game::FB_Game() : Window(900, 500,"Flappy Bird")
{
	InitBackGround();
	score = new FB_Score(this);
	score->SetPosition(sf::Vector2f(width / 2, 0));
}
FB_Game::~FB_Game()
{
	delete background;
	background = nullptr;
	delete score;
	score = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methode
void FB_Game::OnBirdDie()
{
	std::cout <<"Bird is dead !"<< std::endl;
	isStarted = false;
	//TO DO Open game over menu!
}
void FB_Game::Start()
{
	score->Reset();
	FB_GameObjectManager::Instance()->DestroyAllObjects();
	CloseAllMenus();
	isStarted = true;
	bird = new FB_Bird();
	bird->OnDie.SetDynamic(this, &FB_Game::OnBirdDie);
	SpawnPipe();
	spawnerClock.restart();
}
void FB_Game::SpawnPipe()
{
	FB_Pipe* _pipe = new FB_Pipe();
	FB_Pipe* _upPipe = new FB_Pipe();
	_upPipe->Rotate();

	int _random = rand() % 275 + 75;
	_pipe->SetPosition(sf::Vector2f(width + 100, _random + GAP));
	_upPipe->SetPosition(sf::Vector2f(width +100 + _upPipe->GetGlobalBounds().width,  _random));
}
void FB_Game::InitBackGround()
{
	background = new FB_Image(this,"");
	background->SetOrigin(sf::Vector2f(0, 0));
	background->SetPosition(sf::Vector2f(0, 0));
	background->SetScale(sf::Vector2f(3.0f, 3.5f));
}
#pragma endregion methode
#pragma region override
void FB_Game::OnDraw()
{
	//backGround
	background->Draw(this);
	//Menu
	for (std::pair<const char*, BaseMenu*> _pair : menus)
		_pair.second->Draw();
	if (!isStarted) return;
	//GameObject
	FB_GameObjectManager::Instance()->Draw(this);
}
void FB_Game::OnUpdate()
{
	try
	{
		if (!isStarted) return;
		if (spawnerClock.getElapsedTime().asSeconds() >= TIME_FOR_SPAWN)
		{
			SpawnPipe();
			spawnerClock.restart();
		}
		FB_GameObjectManager* _instance = FB_GameObjectManager::Instance();
		_instance->CheckCollision();
		_instance->Update();
		_instance->DestroyAllObjects();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
void FB_Game::InitMenu()
{
	FB_MainMenu* _mainMenu = new FB_MainMenu(this);
	_mainMenu->PlayButton()->OnCLick.SetDynamic(this, &FB_Game::Start);
	_mainMenu->Open();
	RegisterMenu("main menu", _mainMenu);

	FB_GameOverMenu* _gameOverMenu = new FB_GameOverMenu(this);
	_gameOverMenu->RestartButton()->OnCLick.SetDynamic(this, &FB_Game::Start);
	_gameOverMenu->Open();
	RegisterMenu("Game over", _gameOverMenu);
}
#pragma endregion override