#include "Reservation.h"
#include "Client.h"
#include <iostream>
Reservation::Reservation(Reservation& _pCopy)
{
    position = _pCopy.position;
    cursor = _pCopy.cursor;
    
}



void Reservation::Display()
{
    
    std::cin >> cursor;
    system("cls");
    position = cursor;
    PositionUser(position);

    
    
    
}

int Reservation::PositionUser(int _pPosition)
{
    if (_pPosition == 0)
    {
        
        std::cout << "==============Hotel==============" << std::endl;
        std::cout << "1.Reservation" << std::endl;
        std::cout << "2.Quitte " << std::endl;
    }
    else if (_pPosition == 1)
    {
            std::cout << "==============Menu==============" << std::endl;
            std::cout << "2.Reservation" << std::endl;
            std::cout << "3.Remove " << std::endl;
            std::cout << "4.Display " << std::endl;
    }

        else if (_pPosition == 2)
        {
            std::cout << "FirstName" << std::endl;

            std::cout << "LastName" << std::endl;
            std::cout << "date & time of arrival " << std::endl;

            std::cout << "date & time of departure " << std::endl;
        }
        else if (_pPosition == 3)
        {
            std::cout << "Client" << std::endl;
            isEmpty();

            for (int i = 0; i < position; i++)
                std::cout << "" << std::endl;
        }
        else if (_pPosition == 4)
        {
            std::cout << "Remove" << std::endl;
            isEmpty();

            for (int i = 0; i < position; i++)
                std::cout << i << std::endl;
        }
        else
        {
        
        }
   
   return position;
}

bool Reservation::isEmpty()
{
    
    
    return false;
}


void Reservation::Add()
{
}

void Reservation::Delete()
{
}
