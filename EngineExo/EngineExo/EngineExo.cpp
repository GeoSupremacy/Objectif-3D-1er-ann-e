#include <iostream>
#include <crtdbg.h>


#include "Engine/Utils/DebugMacro.h"
#include "Engine/Editor/Asset/AssetWindow.h"
#include "Engine/Editor/Inspector/InspectorWindow.h"
#include "Engine/Window/Engine/EngineWindow.h"
#include "Engine/Manager/GameObject/GameObjectManager.h"
#include "Engine/AssetDataBase/AssetDataBase.h"
#include "Engine/Utils/Interface/Log/ILogger.h"
#include "Test/Reflection/Json/JsonTest.h"
#include "Engine/Manager/FontManager.h"
#include "Engine/Manager/Texture/TextureManager.h"
#include "Assembly.h"


using namespace std;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    cout << "Quel est votre prenom ?" << endl;
    string nomUtilisateur("Sans nom"); //On crée une case mémoire pour contenir une chaine de caractères
    cin >> nomUtilisateur; //On remplit cette case avec ce qu'écrit l'utilisateur

    cout << "Combien vaut pi ?" << endl;
    double piUtilisateur(-1.); //On crée une case mémoire pour stocker un nombre réel
    cin >> piUtilisateur; //Et on remplit cette case avec ce qu'écrit l'utilisateur

    cout << "Vous vous appelez " << nomUtilisateur << " et vous pensez que pi vaut " << piUtilisateur << "." << endl;


    /*Manager::FontManager::Instance()->Init();
    Manager::TextureManager::Instance()->Init();
    Editor::AssetWindow* _assetWindow = new Editor::AssetWindow();
    _assetWindow->OnOpen();
    Editor::InspectorWindow* _inspectorWindow = new Editor::InspectorWindow();
    _inspectorWindow->OnOpen();
    Engine::Window::EngineWindow::Instance()->Open();
   

    Manager::GameObjectManager::Instance()->Destroy();
    Manager::FontManager::Instance()->Destroy();
    Manager::TextureManager::Instance()->Destroy();
    delete _assetWindow;
    delete _inspectorWindow;*/
	return 0;
}
#pragma region re
/*
* 
* 
*  
* 
* 
* 
* 
// Function for demonstration
void replaceDemo(string s1, string s2, string s3, string s4)
{
    // Replaces 7 characters from 0th index by s2

    cout << s1 << endl;

    // Replaces 3 characters from 0th index with "Hello"
    s4.replace(0, 3, "Hello ");
    cout << s4 << endl;

    // Replaces 5 characters from 6th index of s4 with
    // 5 characters from 0th of s3
    s4.replace(6, 5, s3, 0, 5);
    cout << s4 << endl;

    // Replaces 5 characters from 6th index of s4 with
    // 6 characters from string "to all"
    s4.replace(6, 5, "to all", 6);
    cout << s4 << endl;

    // Replaces 1 character from 12th  index of s4 with
    // 3 copies of '!'
    s4.replace(12, 1, 3, '!');
    cout << s4 << endl;


    /*string s1 = "Example of replace";
        string s2 = "Demonstration";
        string s3 = "GeeksforGeeks";
        string s4 = "HeyWorld !";

        replaceDemo(s1, s2, s3, s4);*/
        //Test::JsonTest::Test();
/*Engine::GameObject* _gameObject = Engine::GameObject::CreatePrimitive(PrimitiveType::Circle, "Test");
        _gameObject->AddComponent<Test::PlayerComponent>();

        Engine::AssetDataBase::CreateAsset(_gameObject, "../Asset/GameObjectTest.asset");

        Engine::Window::EngineWindow::Instance()->Open();
        Engine::Manager::GameObjectManager::Instance()->Destroy();*/
#pragma endregion re
