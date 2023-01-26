#include <iostream>

using namespace std;

void CelsiusFahrenheit()
{
    int celsius,
        fahrenheit;
    bool choose;

    cout << " Choose Convert Celsius to Fahrenheit or the reverse (true/false)\n";
    cin >> choose;
    cout << "CC\n";
    if (choose == true)
    {
        cout << "CC1\n";
        cout << "Convert Celsius to Fahrenheit\n";
        cin >> celsius;
        fahrenheit = celsius * 9 / 5 + 32;
        cout << celsius << "C to " << fahrenheit << "F\n";
    }
    else if (choose == false)
    {
        cout << "Convert Fahrenheit to Celsius \n";
        cin >> fahrenheit;
        celsius = (fahrenheit * -32) * 5 / 9;
        cout << celsius << "F to " << fahrenheit << "C\n";
    }
    else
    {
        CelsiusFahrenheit();
        system("CLS");
    }
}
void MeterFeet()
{ 
    int meter,
        feet;

    cout << "Convert meter to feet\n";
    cin >> meter;
    feet = meter * 3.280839895;
    cout << meter << "m to " << feet << "ft";

    cout << "Convert feet to meter\n";
    cin >> feet;
    meter = feet / 0.3048;
    cout << meter << "ft " << feet << "m";
}

void litreGallonUS()
{
    int litre,
        gallionUs;
    cout << "Convert litre to gallon US\n";
    cin >> litre;
    gallionUs = litre /  3.785;
    cout << litre << "L to " << gallionUs << "gal qd";

    cout << "Convert gallon US to litre\n";
    cin >> gallionUs;
    litre = gallionUs / 0.26417;
    cout << gallionUs << "gal qd " << litre << "L";
}

int main()
{
    
    CelsiusFahrenheit();
    
    
}

