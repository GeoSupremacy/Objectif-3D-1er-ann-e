#include "FlappyPipe.h"
#include "FlappyBird.h"
#include "Utils.h"

void FlappyPipe::SetGapPosition(const int _gap)
{
    gapPosition = _gap;
}

void FlappyPipe::SetPosition(const int _position)
{
    position = _position;
}

void FlappyPipe::SetCanDraw(const bool _status)
{
    canDraw = _status;
}

int FlappyPipe::Gaposition() const
{
    return gapPosition;
}

int FlappyPipe::Position() const
{
    return position;
}

bool FlappyPipe::CanDraw() const
{
    return canDraw;
}

void FlappyPipe::Draw()
{

    if (!canDraw) return;
    {
        for (int i = 0; i < gapPosition; i++)
        {
            Utils::SetCursorPosition(WIN_WIDTH - position, i +1);
            std::cout << PIPE;
        }
        for (int i = 0; i < gapPosition; i++)
        {
            Utils::SetCursorPosition(WIN_WIDTH - position, i );
            std::cout << PIPE;
        }
    }
}

void FlappyPipe::Erase()
{
    if (!canDraw) return;
    {
        for (int i = 0; i < gapPosition; i++)
        {
            Utils::SetCursorPosition(WIN_WIDTH - position, i + 1);
            std::cout << Utils::LogSeparator(strlen(PIPE), ' ');
        }
        for (int i = gapPosition + GAP_SIZE; i < SCREEN_HEIGHT; i++)
        {
            Utils::SetCursorPosition(WIN_WIDTH - position, i);
            std::cout << Utils::LogSeparator(strlen(PIPE), ' ');
        }
}

void FlappyPipe::Update()
{
}
