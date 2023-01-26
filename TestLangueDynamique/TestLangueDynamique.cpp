#pragma region Include
#include <iostream>
#include <string>
#pragma endregion 

using namespace std;

#pragma region Instance Methode
void Clear();
void Dictionnaire();
void Language();
void Conversion(int _lang);
void InstanceDYnamiqueTable();
#pragma endregion 
#pragma region GlobalVariable
int const id = 10;

//Choix de numéro pour chaque mot
int choose,
//Lang(1) = fr lang(2) = angl
lang;

//Pour la conversion Engl/Fr ou Fr/Angl
string chooseColor,
word;

//Initaion tableau dynamique
string* tableFrench = nullptr;
string* tableEnglish = nullptr;
int tableSize = 0;

#pragma endregion
#pragma region ListWordEnglish
//Liste de mot en anglais
string listWordEnglish[id] = {

         "black",
         "white",
         "green",
         "red",
         "blue",
         "yellow",
         "orange",
         "brown",
         "purple",

};

#pragma endregion
#pragma region ListWordFrensh
//Liste de mot en francais
string listWordFrench[id] = {

     "noir",
     "blanc",
    "vert",
     "rouge",
     "bleu",
     "jaune",
     "orange",
     "marron",
     "violet",

};


#pragma endregion
#pragma region InstanceDYnamiqueTable
void InstanceDYnamiqueTable()
{
    string* _tmpFR = tableFrench;
    string* _tmpENG = tableEnglish;
    for (size_t i = 0; i <id; i++) 
    {
        tableSize++;
        
    }
    
    tableFrench = new string[tableSize];
    tableEnglish = new string[tableSize];
    
    for (size_t i = 0; i < id; i++) //(sizeArray-1) c'est pour l'occurence Au début il n'y a rien mais avt on a ajouter une ocurence
    {
        
        tableFrench[i] = _tmpFR[i]; // La nouvel table prend l'ancien mais avec ses caractéristiques
        
        tableEnglish[i] = _tmpENG[i];
        
        tableFrench[i] = listWordFrench[i];
        tableEnglish[i] = listWordEnglish[i];
        
    }
    
}
#pragma endregion
#pragma region Dictionnaire
void Dictionnaire()
{
    string  dictionary;
    bool translate;

    cout << "Do you want to modify in the dictionary or not? O/N \n ";
    cin >> dictionary;

    if (dictionary == "O")
    {
        cout << "listWordFrench " << endl;
        int iD;
        for (int i = 0; i < 9; i++)
        {

            cout << "[" << i << "] " << listWordFrench[i] << endl;


        }

        cout << "Do you want to Add, Delete, Modify? \n or exit ? \n A/D/M or S ";
        cin >> dictionary;
        if (dictionary == "A")
        {

            cout << "Add a new French word : ";
            cin >> word;

            listWordFrench[9] = word;
            cout << "listWordEnglish" << endl;
            for (int i = 0; i < 9; i++)
            {

                cout << "[" << i << "] " << listWordEnglish[i] << endl;

            }
            cout << "Add its equivalent in English: \n";
            cin >> word;
            listWordEnglish[9] = word;
            system("CLS");
            cout << "listWordFrench" << endl;

            for (int i = 0; i < 10; i++)
            {

                cout << "[" << i << "] " << listWordFrench[i] << endl;

            }
            cout << "\n";
            cout << "listWordEnglish" << endl;
            for (int i = 0; i < 10; i++)
            {

                cout << "[" << i << "] " << listWordEnglish[i] << endl;

            }
            cout << "Tap any key to exit \n";
            cin >> word;
            system("CLS");
        }
    }

    else if (dictionary == "N")
    {
        system("CLS");
    }
    else
    {
        Dictionnaire();
    }
}
#pragma endregion
#pragma region Language
void Language()
{
    int _lang = 0;
    cout << "Choose your language to translate: \n"
        << "[1] Francais -> Anglais \n"
        << "[2] English -> French\n"
        << "Choice number of language: ";
    cin >> _lang;

    //vérification de l'entré utilisateur
    if (_lang > 2 || _lang < 1)
    {
        cout << "Invalid number";
        Language();
    }
    else
    {
        if (_lang == 1)
        {
            _lang = _lang;
        }
        else if (_lang == 2)
        {
            _lang = _lang;
        }
    }
}
#pragma endregion
#pragma region Conversion
void Conversion(int _lang)
{
    //Si la langue est francaise

    if (_lang == 1)
    {

        for (int i = 0; i < id; i++)
        {
            cout << "[" << i << "] " << listWordFrench[i] << endl;

        }
        cout << "Choisir le mot (numero) a traduire: ";


        //vérification de l'entré utilisateur
        cin >> choose;
        if (choose > 9 || choose < 1) {
            cout << "\nNombre invalide\n Recommence: ";
            Conversion(lang);
        }

        for (int i = 0; i < id; i++)
        {
            if (choose == i)
            {
                chooseColor = listWordFrench[i];
                cout << chooseColor << " -> " << listWordEnglish[i];
            }

        }

    }

    else if (_lang == 2)
    {

        for (int i = 0; i < id; i++)
        {
            cout << "[" << i << "] " << listWordFrench[i] << endl;

        }
        cout << "Choisir le mot (numero) a traduire: ";


        //vérification de l'entré utilisateur
        cin >> choose;
        if (choose > 9 || choose < 1) {
            cout << "\nNombre invalide\n Recommence: ";
            Conversion(lang);
        }

        for (int i = 0; i < id; i++)
        {
            if (choose == i)
            {
                chooseColor = listWordFrench[i];
                cout << chooseColor << " -> " << listWordEnglish[i];
            }
        }
    }

    else
    {
        cout << "Language??";
    }

}
#pragma endregion 
#pragma region Clear
void Clear()
{
    tableSize = 0;
    delete[] tableFrench,
        tableEnglish;
}
#pragma endregion
int main()
{
    InstanceDYnamiqueTable();
    //Dictionnaire();
    //Language();
    //Conversion(lang);
    Clear();
}

