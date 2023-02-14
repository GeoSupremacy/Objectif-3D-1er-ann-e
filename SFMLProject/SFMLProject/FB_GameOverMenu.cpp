#include "FB_GameOverMenu.h"
#include "Window.h"
#include "FB_Image.h"
#include "FB_Button.h"

#pragma region constructor/destructor
FB_GameOverMenu::FB_GameOverMenu(Window* _owner) : BaseMenu(_owner)
{
    const float _with = Window.with;
    const float _height = Window.height;
    InitRestartButton(_with, _height);
    InitTitleImage(_with);
    InitGameOverImage(_with, _height);
}
FB_GameOverMenu::~FB_GameOverMenu()
{
    delete gameOverImage;
    gameOverImage = nullptr;
    delete titleImage;
    titleImage = nullptr;
    delete restartButton;
    restartButton = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods
void FB_GameOverMenu::InitRestartButton(const float _width, const float _height)
{
    restartButton = new FB_Button(owner, "C:/Users/GUIC1203/source/repos/Cours/Cours Thomas/SFMLProject/Fonts/FlappyBird/flappybird_play_button.png");
    restartButton->SetScale(sf::Vector2f(0.3f, 0.3f));
    restartButton->SetPosition(sf::Vector2f(_width-( restartButton->GetGlobalBounds().width +100), _height));
    elements.push_back(restartButton);
}
void FB_GameOverMenu::InitTitleImage(const float _width)
{
    titleImage = new FB_Image(owner, "C:/Users/GUIC1203/source/repos/Cours/Cours Thomas/SFMLProject/Fonts/FlappyBird/Flappy_Logo.png");
    titleImage->SetPosition(sf::Vector2f(_width - 150, 20));
    titleImage->SetScale(sf::Vector2f(0.1f, 0.1f));
    sf::Vector2f _position = sf::Vector2f(_width - (titleImage->GetGlobalBounds().width / 2),titleImage->GetGlobalBounds().height() / 2);
    elements.push_back(titleImage);
}
void FB_GameOverMenu::InitScoreText(const float _with, const float _height)
{
    scoreText = new FB_Label();
}
void FB_GameOverMenu::InitGameOverImage(const float _width, const float _height)
{
    gameOverImage = new FB_Image(owner, "C:/Users/GUIC1203/source/repos/Cours/Cours Thomas/SFMLProject/Fonts/FlappyBird/flappyBirdGameOver.png");
    gameOverImage->SetScale(sf::Vector2f(0.2f, 0.2f));
    sf::Vector2f _position = sf::Vector2f(_width - (gameOverImage->GetGlobalBounds().width / 2),
        _height - (gameOverImage->GetGlobalBounds().height() / 2));
    elements.push_back(_position);
}
FB_Button* FB_GameOverMenu::RestartButton() const
{
    return restartButton;
}
#pragma endregion methods
#pragma region override
void FB_GameOverMenu::Draw()
{
}

#pragma endregion override