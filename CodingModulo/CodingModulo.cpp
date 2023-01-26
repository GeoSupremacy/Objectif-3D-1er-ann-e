#include <iostream>
#include <string>
#include <random>


int main()
{
    unsigned short i;
    short tab1[5] = { 1, 2, 3, 4, 5 };
    short tab2[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    short* t1;
    short* t2;

    t1 = tab1;
    t2 = tab2;

    // Affichage des tableaux pointés
    // par les deux pointeurs, au départ :
    
    printf("Tableau correspondant à t1:\n");
    for (i = 0; i < 5; i++)
        printf("t1[%u]=%d\n", i, t1[i]);
    
    
    printf("Tableau correspondant à t2:\n");
    for (i = 0; i < 10; i++)
        printf("t2[%u]=%d\n", i, t2[i]);
   

    // Echange des deux pointeurs :
    short* temp;
    temp = t1;
    t1 = t2;
    t2 = temp;

    // Et affichage, après échange :
   
    printf("Tableau correspondant à t1:\n");
    for (i = 0; i < 10; i++)
        printf("t1[%u]=%d\n", i, t1[i]);
  
    printf("Tableau correspondant à t2:\n");
    for (i = 0; i < 5; i++)
        printf("t2[%u]=%d\n", i, t2[i]);

    printf("Tableau1:\n");
    for (i = 0; i < 10; i++)
        std::cout<<tab1[i];

    printf("tab2:\n");
    for (i = 0; i < 5; i++)
        std::cout<<tab2[i];
    
}
#pragma region Multiplication table
   /* short tab[10][3];  // Tableau à 10 lignes et 3 colonnes
                          // (puisque je considère que la première dimension correspond aux lignes, et la seconde aux colonnes)
    short i = 0,
        j = 0;

    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 10; i++)
        {
            tab[i][j] = (i + 1) * (j + 5);   // i+1 car on veut que la table de multiplications
                                      //aille de 1 à 10 (et non de 0 à 9)
                    // j+5 car on veut les tables de multiplication de 5, 6, et 7
                                      // (j allant de 0 à 2 compris)
        }
        
    }

    // tab[i][1] (i variant de 0 à 9 compris) vaut
    // maintenant {6, 12, 18, 24, 30, 36, 42, 48, 54, 60)
    // Pour vérifier, affichons tab[i][1] (table de multiplication de 6) :
    for (i = 0; i < 10; i++)
    {
        printf("7*%d = %d\n", i + 1, tab[i][2]);
    }
    */
#pragma region Without table
 /*  
    short a = 0,
        b = 0;

    
    for (a = 0; a < 10; a++)
    {
        printf("% 2d* ", i + 1);
        for (b = 0; b < 3; b++)
        {
            printf("%d=% 2d ", b + 5, (a + 1) * (b + 5));
        }
        printf("\n");
    }
    */
#pragma endregion 
#pragma endregion 
#pragma region Tri
/*
short tab[10];
short i, j;
short temp;

int A[3][10] = { {0,0,0,0,0,0,0,0,0,0}, };
srand((unsigned int)time(0));

for (i = 0; i < 10; i++)
{ // On remplit le tableau avec des données aléatoires
    tab[i] = rand()%20;
}


printf("Données non triées :\n");
for (i = 0; i < 10; i++)
{ // On affiche les données (non triées) contenues dans le tableau
    printf("%d ", tab[i]);
}



// Tri des données par ordre croissant :
for (i = 0; i < 10; i++)//1
{
    for (j = i + 1; j < 10; j++)//par 10
    {
        if (tab[j] < tab[i])
        { // On inverse
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }
}

printf("\nDonnées triées :\n");
for (i = 0; i < 10; i++)
{ // On affiche les données (qui, maintenant, sont triées) contenues dans le tableau
    printf("%d ", tab[i]);
}
*/
#pragma endregion 
#pragma region Modulo
	/*
	std::string coding = "067111100105110103";
	if (coding.size() % 3 != 0)
	{
		std::cout << "ERROR3" << std::endl;
		return 0;
	}
		std::string _result = "";
		int _index = 0;
		for (int i = 3; i <= coding.size(); i += 3)
		{
			std::string _str = coding.substr(_index, 3);
			_index = i;
			int _value = std::atoi(_str.c_str());
			_result += (char)_value;
		}
		std::cout << _result << std::endl;
	*/

#pragma endregion 

