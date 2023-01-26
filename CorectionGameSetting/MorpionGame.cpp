#include "MorpionGame.h"
#include "MorpionBoard.h"
#include "MorpionAI.h"
#include "Utils.h"
#include <format>
MorpionGame::MorpionGame()
{
    board = new MorpionBoard();
}

MorpionGame::~MorpionGame()
{
    delete board;
    delete ai;
}

void MorpionGame::OnStart()
{
    winner = 0;
}

void MorpionGame::OnEnd()
{
}

void MorpionGame::OnUpdate()
{
    int _moves = 0;
    while (winner == 0 && _moves < 9)
    {
        Utils::ClearConsole();
        board->ShowBoard();
        const bool _isPlayerTwo = currentPlayer % 2 == 0;
        int _currentMove = ai->BestMove(*board);
        if (_isPlayerTwo && ai != nullptr)
        {
            
            board->At(_currentMove) = 1;
        }
        else
        {
            Utils::Log(std::format("Player {} turn: ", _isPlayerTwo ? 2 : 1));
            _currentMove = Utils::UserChoise<int>("Oh oh",1,2,3);
            if(_currentMove <=0 || _currentMove >9)
                throw std::exception("");
            if (board->At(_currentMove - 1) == 0)
            {
                board->At(_currentMove - 1) = _isPlayerTwo ? 1 : -1;
            }
        }
        currentPlayer++;
        winner = board->Win();
    }
}
void MorpionGame::PlayerTurn(const bool& _isPlayerTwo, int& _moves)
{
    Utils::Log(std::format("Player {}: turn:", _isPlayerTwo ? 2 : 1));
    int _currentMove = Utils::UserChoice<int>("");
    if (_currentMove <= 0 || _currentMove >9)
    {
        throw std::exception("[MORPION GAME] => Move out of range!");
    }
    if (board->At(_currentMove - 1) == 0)
    {
        board->At(_currentMove - 1) = _isPlayerTwo ? 1 : -1;
        _moves++;
    }
}
void MorpionGame::DisplayMenu()
{
    
    Utils::ClearConsole();
    Utils::LogTitle(GameName());
    const std::string _msg = "1- >Player vs Player\n2 - Player vs AI\n";
    char _choice = Utils::UserChoise<char>("Choose",'0','1','2');
    if (_choice == '2')
        ai = new MorpionAI();
    else
    {
        delete ai;
        ai = nullptr;
    }
    _choice = Utils::UserChoise<char>("Do you want to start first? (y/n): ", '-', 'y', 'n');
    currentPlayer = _choice == 'y' ? 1 : 2;
}
std::string MorpionGame::GameName()
{
    return "Morpion";
}
std::string MorpionGame::GamDescription()
{
    return "Morpion game, you can play with another player or with a AI";
}