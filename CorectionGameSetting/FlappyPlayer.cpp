#include "FlappyPlayer.h"
#include "Utils.h"

int FlappyPlayer::Position() const
{
	return position;
}

int FlappyPlayer::IsDead() const
{
	return isDead;
}

void FlappyPlayer::SetPosition(const int _position)
{
	position = _position;
}

bool FlappyPlayer::SetDead(const bool _statue)
{
	isDead = _statue;
	bird[0][3] = isDead ? 'x' : '0';
}

void FlappyPlayer::Jump()
{
	if (position > 3)
	{
		position -= 3;
	}
}

void FlappyPlayer::Draw()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			Utils::SetCursorPosition(j + 2, i + position);
			std::cout <<bird[i][j];
		}
		
	}
}

void FlappyPlayer::Erase()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			Utils::SetCursorPosition(j + 2, i + position);
			std::cout <<" ";
		}

	}
}

void FlappyPlayer::Update()
{
	position += 1;
}
