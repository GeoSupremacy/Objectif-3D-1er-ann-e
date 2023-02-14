// ConsoleImput.cpp : Afficher des boutons dans le windows

#include <iostream>
#include "App.h"
#include "Button.h"
#include "Rect.h"
#include "EventSystem.h"

int main()
{
    Button* b1 = new Button("Recherche","recherche", new Rect(5, 100, 0, 0)); //Width//Height//X//Y
    //Button* b2 = new Button("Hello","list", new Rect(5, 1, 10, 15)); //Width//Height//X//Y
   EventSystem::Instance()->Register(b1);
   // EventSystem::Instance()->Register(b2);
    App app;
    app.Open();
}
