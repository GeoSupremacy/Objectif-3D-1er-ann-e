#pragma once
#include <iostream>
#include<string>
#include <map>
#include <vector>


class HashTable
{
#pragma region f/p
protected:
    std::map< std::string, std::string> map = std::map<std::string, std::string>(); //La map
    int  size = 14;
  
    std::string alphabet = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklnmopqrstuvwxyz"; //La table de hachage va convertir le mot de l'alphabet par 
    std::string convert = " sgd3gdsvx6db&c:n^sjsovqckn skncsifknxw:,cbnl hrqomidf";//un mot de 'convert' grace à sa position dans la chaine
    //Nos cobayes
    std::vector<std::string> nameClassProg1= {
        "Thomas","Antoni", "Benoit", "Damien","Gabriel", "Giusy", "Hugo","Kevin", "Mathieu", "Morgan","Pierre-Louis", "Thibaud D","Thibaud Boivin","Romain"
    };  
#pragma endregion f/p
#pragma region constructor/destructor
public:
    HashTable();
#pragma endregion constructor/destructor
#pragma region methods
protected:
    int Random(const int _range);//Pour générer aléatoirement des noms
    void Init(const int _nbrElement, const int _sizeMap); //Pour initialiser de nouveau élément(j'utilse des cobayes au lieu de générer aléatoirement des noms juste 20 entités sa prends 1 min)
    std::string Hachage(std::string _hach);//El famoso table de hachage
    
public:
    void Found(std::string  _indice); //Parcour la map et dit s'il trouve ou non
    void Selected();
    void Lack(); //Pour vérifier s'il manque pas un cobaye dans la map
#pragma endregion methods

};

