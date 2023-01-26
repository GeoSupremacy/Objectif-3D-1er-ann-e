#include <iostream>

using namespace std;
#pragma region ListColorEnglish
//Liste de couleur en anglais
string listColorEnglish[] = {
            "",
           "black",
         "white",
         "green",
         "red",
         "blue",
         "yellow",
         "orange",
         "brown",
         "purple"
};
string black = "black",
white = "white",
green = "green",
red = "red",
blue = "blue",
yellow = "yellow",
orange = "orange",
brown = "brown",
violet = "violet";
#pragma endregion

#pragma region ListColorFrensh
//Liste de couleur en francais
string listColorFrench[] = {
        "",
     "noir",
     "blanc",
    "vert",
     "rouge",
     "bleu",
     "jaune",
     "orange",
     "marron",
     "violet"
};
string noir = "noir",
blanc = "blanc",
vert = "vert",
rouge = "rouge",
bleu = "bleu",
jaune = "jaune",
orange1 = "orange",
marron = "marron",
violet1 = "violet";

#pragma endregion

//Choix de numéro pour chaque couleur
int choose,
//Lang(1) = fr lang(2) = angl
lang;

//Pour la conversion Engl/Fr ou Fr/Angl
string chooseColor;

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
            lang = _lang;
        }
        else if (_lang == 2)
        {
            lang = _lang;
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
        cout << "[1] Noir \n"
            << "[2] Blanc \n"
            << "[3] Vert \n"
            << "[4] Rouge \n"
            << "[5] Bleu \n"
            << "[6] Jaune \n"
            << "[7] Orange \n"
            << "[8] Marron \n"
            << "[9] Violet \n"
            << "Choisir le mot (numéro) à traduire: ";


        //vérification de l'entré utilisateur
        cin >> choose;
        while (choose > 9 || choose < 1) {
            cout << "\nNombre invalide\n Recommence: ";
            cin >> choose;
        }

        if (choose == 1)
        {
            chooseColor = listColorFrench[1];
            cout << chooseColor << " -> " << listColorEnglish[1];
        }
        else if (choose == 2)
        {
            chooseColor = listColorFrench[2];
            cout << chooseColor << " -> " << listColorEnglish[2];
        }
        else if (choose == 3)
        {
            chooseColor = listColorFrench[3];
            cout << chooseColor << " -> " << listColorEnglish[3];
        }

        else if (choose == 4)
        {
            chooseColor = listColorFrench[4];
            cout << chooseColor << " -> " << listColorEnglish[4];
        }
        else if (choose == 5)
        {
            chooseColor = listColorFrench[5];
            cout << chooseColor << " -> " << listColorEnglish[5];
        }
        else if (choose == 6)
        {
            chooseColor = listColorFrench[6];
            cout << chooseColor << " -> " << listColorEnglish[5];
        }
        else if (choose == 7)
        {
            chooseColor = listColorFrench[7];
            cout << chooseColor << " -> " << listColorEnglish[7];
        }
        else if (choose == 8)
        {
            chooseColor = listColorFrench[8];
            cout << chooseColor << "Simplement" << listColorEnglish[8];
        }
        else if (choose == 9)
        {
            chooseColor = listColorFrench[9];
            cout << chooseColor << " -> " << listColorEnglish[9];
        }
        else
            cout << "Se n'est pas une couleur";
    }

    else if (_lang == 2)
    {
        //Si la langue est anglaise
        cout << "[1] Black \n"
            << "[2] White \n"
            << "[3] Green \n"
            << "[4] Red \n"
            << "[5] Blue \n"
            << "[6] Yellow \n"
            << "[7] Orange \n"
            << "[8] Brown \n"
            << "[9] Purple \n"
            << "Choose the word (number) to translate: ";


        //vérification de l'entré utilisateur
        cin >> choose;
        while (choose > 9 || choose < 1)
        {
            cout << "\nInvalid number\n Retry: ";
            cin >> choose;
        }
        if (choose == 1)
        {
            chooseColor = listColorEnglish[1];
            cout << chooseColor << " to " << listColorFrench[1];
        }
        else if (choose == 2)
        {
            chooseColor = listColorEnglish[2];
            cout << chooseColor << " to " << listColorFrench[2];
        }
        else if (choose == 3)
        {
            chooseColor = listColorEnglish[3];
            cout << chooseColor << " to " << listColorFrench[3];
        }
        else if (choose == 4)
        {
            chooseColor = listColorEnglish[4];
            cout << chooseColor << " to " << listColorFrench[4];
        }
        else if (choose == 5)
        {
            chooseColor = listColorEnglish[5];
            cout << chooseColor << " to " << listColorFrench[5];
        }
        else if (choose == 6)
        {
            chooseColor = listColorEnglish[6];
            cout << chooseColor << " to " << listColorFrench[6];
        }
        else if (choose == 7)
        {
            chooseColor = listColorEnglish[7];
            cout << chooseColor << " just " << listColorFrench[7];
        }
        else if (choose == 8)
        {
            chooseColor = listColorEnglish[8];
            cout << chooseColor << " to " << listColorFrench[8];
        }
        else if (choose == 9)
        {
            chooseColor = listColorEnglish[9];
            cout << chooseColor << " to " << listColorFrench[9];
        }
        else
        {
            cout << "This is not colour \n";
        }

    }
    else
    {
        cout << "Language??";
    }



}
#pragma endregion 

int main()
{
    Language();
    Conversion(lang);
}

