//Menu Play
//Menu setting Ai vs Player
//Want to play first
//MorpionX
#include <iostream>
#include "Launcher.h"
#include "LauncherItem.h"
#include "Menu.h"
#include <windows.h>

int main()
{
    SetConsoleTitle(L"Launcher");
    Menu menu;
    menu.DisplayMenu();
}


#pragma region Example
/*
    SetConsoleTitle(L"Launcher");
    Launcher _launcher = Launcher(
        {
            new LauncherItem(new TicTacToe())
            //new LaungherItem(new MorpionGame())
        });

    _launcher.Open();
    */
#pragma endregion Example
