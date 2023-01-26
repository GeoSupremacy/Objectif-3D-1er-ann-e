#include "Reservation.h"

int main()
{
    while (true)
    {
        Reservation _reservation;
        _reservation.Display();
    }
}

/*
Le context: Afficher un interface de réservation d'hotel.
L'utilisateur tape une suite de commande prédéterminer pour aller d'une page à une autre
Class
    Hotel
        Position
        Cursor
        VDisplay
     M
        Diplay
        Condition par Position
        Contion ifempty
        ChooseCursor
        Add/Delete CLient

Client
    FirstName/LastName
    Age
    Date B/A
    (JJ/m/AA)(H/m/s)

    M
        Display
        Add:Delete
        CreateNode
 
Display
Boucle isRestHotel
Menu 
Variable Menu & Reserve & quitte[d] -> display
        Position
        Cursor ->COndition [c]
        Condition
        Si 1 
        Reserve
        Si 2 
        !isRestHotel
        "Thank to visit"
Reserve
    Variable[d] Add Remove Display  -->Display
        [c]

To do
    Class
    Hotel
    Main
    Client

*/
