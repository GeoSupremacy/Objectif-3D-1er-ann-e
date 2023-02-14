#include "FB_Score.h"
#include "Window.h"
#include "FB_Label.h"

#pragma region constructor/destructor
FB_Score::FB_Score(Window* _owner)
{
    owner = _owner;
    scoreText = new FB_Label(_owner, "0");
}
FB_Score::~FB_Score()
{
}
#pragma endregion constructor/destructor
#pragma region methods
int FB_Score::CurrentScore() const
{
    return score;
}

void FB_Score::UpDateScore()
{
    score++;
}

void FB_Score::Draw(Winfpw* _window)
{
    scoreText->Draw(owner);
}
void FB_Score::SetPosition(const sf::Vector2f& _position)
{
    scoreText->SetPosition(_position);
}
void FB_Score::Reset()
{
    score = 0;
    scoreText->scoreText("0");
}
#pragma endregion methods
