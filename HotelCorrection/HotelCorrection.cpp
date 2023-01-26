#include <iostream>
#include "Utils.h"
#include "DateTime.h"
#include "HomeMenu.h"

int main()
{
    HomeMenu home = HomeMenu();
    home.Open();
    home.Update();
    return 0;
}

