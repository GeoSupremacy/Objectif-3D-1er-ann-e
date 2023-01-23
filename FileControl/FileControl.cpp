#include <iostream>
#include <filesystem>
#include "File.h"
int main()
{
    auto path = std::filesystem::current_path();
    std::filesystem::current_path(path);
   
    //File _you;
    //_you.CMDEXE();
    return 0;
}
#pragma region Context
/*
* 
    std::locale::global(std::locale{ "" });
    std::string command;
    std::ofstream fileE1("C:/Users/GUIC1203/Desktop/Prog1/otherFile.txt");

    if(fileE1)
    {
        fileE1 <<"Great you can read" <<std::endl;
        fileE1 << "Great you can read" << std::endl;
    }
    else
    {
        std::cout << "Sorry file doesn't exit" << std::endl;
    }
* Afficher fichier courant Utilisateur
* Taper commande
*   Help afficher toute les commandes et description
* Commande == opération     
*/
#pragma endregion Context