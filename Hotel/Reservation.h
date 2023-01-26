/*Class
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
*/
#include <string>
class Reservation
{
private:
    
    int cursor = 0;
    int position = 0;

public:
    
    Reservation() = default;
    Reservation(Reservation& _pCopy);
    
public:
    void Display();
    int PositionUser(int _pPosition);
    bool isEmpty();
    int ChooseCursor(int _pCursor);
    void Add();
    void Delete();
};

