#pragma region include 
#include <iostream>
#include <string>
#pragma endregion
using namespace std;


#pragma region Identification 
string  firstName = "",
        lastName = "";
int age = 0;
#pragma endregion

#pragma region Calcule 
int firstNumber = 0,
    secondNumber = 0,
    result = 10;
#pragma endregion   
#pragma region language 
string frLocfirstName = "Prenom\n",
frLoclastName = "Nom \n",
frLocAge = "Age \n",
FrLocResultOne = "Mon nom est: ",
FrLocResultTwo = "est je suis age de ",
FrLocResultThree = " ans.";
#pragma endregion

void Identification(string _frLocfirstName, string _frLoclastName, string  _frLocAge, string _FrLocResultOne, string _FrLocResultTwo, string _FrLocResultThree)
{
    cout << _frLocfirstName;
    cin >> firstName;

    cout << _frLoclastName;
    cin >> lastName;

    cout << _frLocAge;
    cin >> age;

    cout << _FrLocResultOne << firstName << " " << lastName << " " << _FrLocResultTwo << to_string(age) << _FrLocResultThree << "\n";
}


void ShowCalculate()
{
    cout << "Number 1: \n";
    cin >> firstNumber;
    cout << "Number 2: \n";
    cin >> secondNumber;
}

int Add()
{
    return
    result = firstNumber + secondNumber;

}

int sub()
{
    return
    result = firstNumber - secondNumber;

}
int mult()
{
    return
    result = firstNumber * secondNumber;

}
int div()
{
    return
    result = firstNumber / secondNumber;

}

void GetResultat()
{
    ShowCalculate();
    Add();

    cout << "Addition: " << to_string(result) <<"\n";

    sub();
    cout << "subtraction: " << to_string(result) << "\n";

    mult();
    cout << "multiplication: " << to_string(result) << "\n";

    div();
    cout << "division: " << to_string(result) << "\n";
}
int main()
{
    Identification(frLocfirstName, frLoclastName, frLocAge, FrLocResultOne, FrLocResultTwo, FrLocResultThree);
    
    

    GetResultat();
    
    return 0;
    
}
 
