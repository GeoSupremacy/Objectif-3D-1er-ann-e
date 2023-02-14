#include "FB_MainMenu.h"
#include "FB_Image.h"
#include "FB_Button.h"
#include "Window.h"

#pragma region constructor/destructor
FB_MainMenu::FB_MainMenu(Window* _owner) : BaseMenu(_owner)
{
	InitPlayButton();
	InitLogoTitle();
}
FB_MainMenu::~FB_MainMenu()
{
/*	delete logoTilte;
	logoTilte = nullptr;
	delete background;
	background = nullptr;
	delete playButton;
	playButton = nullptr;
	delete scoreboardButton;
	scoreboardButton = nullptr;*/
}
#pragma endregion constructor/destructor
#pragma region methods
void FB_MainMenu::InitPlayButton()
{
	playButton = new FB_Button(owner, "C:/Users/GUIC1203/source/repos/Cours/Cours Thomas/SFMLProject/Fonts/FlappyBird/play_button.png");
	playButton->SetScale(sf::Vector2f(0.3f, 0.3f));
	const sf::Vector2f _position = sf::Vector2f((owner->Width() / 2) - (playButton->GetGlobalBounds().width + 100), owner->Height() / 2);
	playButton->SetPosition(_position);
	elements.push_back(background);
}
void FB_MainMenu::InitLogoTitle()
{
	logoTilte = new FB_Image(owner, "C:/Users/GUIC1203/source/repos/Cours/Cours Thomas/SFMLProject/Fonts/FlappyBird/Flappy_Logo.png");
	logoTilte->SetPosition(sf::Vector2f((owner->Width()/ 2), 50));
	logoTilte->SetScale(sf::Vector2f(0,0));
	logoTilte->SetOrigin(sf::Vector2f(logoTilte->GlobalBounds().width/2, logoTilte->GlobalBounds().height / 2));
	elements.push_back(logoTilte);
}
FB_Button* FB_MainMenu::PlayButton() const
{
	return playButton;
}
FB_Button* FB_MainMenu::ScoreboardButton() const
{
	return scoreboardButton;
}
void FB_MainMenu::Draw()
{
	BaseMenu::Draw();

}
#pragma endregion methods
